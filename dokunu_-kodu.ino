#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

#define SS1 10
#define SS2 7
#define SS3 6
#define RST 9
#define BTN_MOD A0   // Mod değiştirme butonu
#define BTN_ONAY A1  // Onaylama butonu

// ========================================================
// SES DOSYASI NUMARALARI VE SÜRE AYARLARI
// ========================================================
int sistemBasladiSesi = 0; // Açılış sesi (0004.mp3)
int mod1Sesi = 13;          // Eğitim Modu sesi (0013.mp3)
int mod2Sesi = 14;          // Hece Modu sesi (0014.mp3)
int mod3Sesi = 15;          // Sayı Modu sesi (0015.mp3)

int dogruCevapSesi = 11;    // Doğru cevap sesi (0011.mp3)
int yanlisCevapSesi = 12;   // Yanlış cevap sesi (0012.mp3)

// SÜRELER (Milisaniye cinsinden. 1000 ms = 1 Saniye)
unsigned long acilisSesiSuresi = 5000;  // Sistem başladı sesinin süresi (5 saniye)
unsigned long modGecisSuresi = 2500;    // Mod anons sesinin süresi (2.5 saniye)
unsigned long dogruYanlisSuresi = 3000; // Doğru/Yanlış sesinin süresi (3 saniye)
// ========================================================

MFRC522 rfid1(SS1, RST);
MFRC522 rfid2(SS2, RST);
MFRC522 rfid3(SS3, RST);

SoftwareSerial mySerial(5, 4); // RX, TX
DFRobotDFPlayerMini dfplayer;

// Yuvalardan okunan anlık harfler/rakamlar
String yuva1 = "", yuva2 = "", yuva3 = "";
int sira = 1; // 1: 1. Yuva, 2: 2. Yuva, 3: 3. Yuva, 4: Buton Bekleme aşaması

int guncelMod = 1; 
bool yeniSoruSor = true;
String beklenenCevap = "";

// HATA VEREN DEĞİŞKEN BURAYA EKLENDİ (Eğitim modunun kararlı çalışması için)
char sonOkunanKup = '?'; 

bool lastModButtonState = HIGH;
bool lastOnayButtonState = HIGH;
unsigned long sonModZamani = 0;
const int debounceGecikmesi = 200; // Mod butonu parazit engelleme süresi

struct KartBilgisi {
  byte uid[4];
  String harf;
  int sesDosyasi;
};

KartBilgisi kartlar[] = {
  {{0xFF, 0x0F, 0xC3, 0x19}, "A", 1},
  {{0xFF, 0x0F, 0x54, 0x21}, "E", 2},
  {{0xFF, 0x0F, 0x55, 0x21}, "I", 3},
  {{0xFF, 0x0F, 0x67, 0x18}, "N", 4},
  {{0xFF, 0x0F, 0xD3, 0xFD}, "L", 5},
  {{0xFF, 0x0F, 0xD4, 0xFD}, "T", 6},
  {{0xFF, 0x0F, 0xD6, 0xFD}, "3", 7},
  {{0xFF, 0x0F, 0xD5, 0xFD}, "2", 8},
  {{0xFF, 0x0F, 0xC2, 0x19}, "1", 9}
};

String heceSorular[] = {"TEL", "EL", "AT", "NIL", "TAN", "IN", "ALI"};
int heceSesleri[] = {17, 18, 19, 20, 21, 22, 23};
String sayiSorular[] = {"12", "32", "123", "213", "23"};
int sayiSesleri[] = {24, 25, 26, 27, 28};

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; } 
  
  Serial.println("Sistem baslatiliyor...");

  mySerial.begin(9600);
  SPI.begin();

  pinMode(SS1, OUTPUT); digitalWrite(SS1, HIGH);
  pinMode(SS2, OUTPUT); digitalWrite(SS2, HIGH);
  pinMode(SS3, OUTPUT); digitalWrite(SS3, HIGH);
  
  pinMode(BTN_MOD, INPUT_PULLUP);
  pinMode(BTN_ONAY, INPUT_PULLUP);

  rfid1.PCD_Init(); rfid2.PCD_Init(); rfid3.PCD_Init();
  
  if (!dfplayer.begin(mySerial)) {
    Serial.println("DFPlayer baglantisi kurulamadi! Kablolari kontrol et.");
  } else {
    Serial.println("DFPlayer basarili.");
    dfplayer.volume(25);
    
    // Sistem Açılış Akışı
    dfplayer.playMp3Folder(sistemBasladiSesi);
    delay(acilisSesiSuresi); 
    
    dfplayer.playMp3Folder(mod1Sesi);
    delay(modGecisSuresi);  
  }
  
  Serial.println("Mod 1: Egitim Modu Aktif. 1. Yuvaya kart koyun.");
}

void loop() {
  // 1) MOD BUTONU KONTROLÜ (Eğitim / Hece / Sayı Seçimi)
  bool currentModButton = digitalRead(BTN_MOD);
  if (lastModButtonState == HIGH && currentModButton == LOW) {
    if ((millis() - sonModZamani) > debounceGecikmesi) {
      guncelMod++;
      if (guncelMod > 3) guncelMod = 1;
      
      Serial.print("Mod degisti: "); Serial.println(guncelMod);
      
      // Yeni modun başlangıç sesini çal
      if (guncelMod == 1)      dfplayer.playMp3Folder(mod1Sesi);
      else if (guncelMod == 2) dfplayer.playMp3Folder(mod2Sesi);
      else if (guncelMod == 3) dfplayer.playMp3Folder(mod3Sesi);
      
      delay(modGecisSuresi); // Mod sesinin bitmesini beklet
      
      // Durumu sıfırla
      sira = 1; yuva1 = ""; yuva2 = ""; yuva3 = "";
      yeniSoruSor = true;
      sonModZamani = millis();
    }
  }
  lastModButtonState = currentModButton;

  // 2) SEÇİLİ MODA GÖRE ÇALIŞMA AKIŞI
  if (guncelMod == 1) {
    // MOD 1: EĞİTİM (Kart okundukça harf sesi çıkarır, buton kontrolü yoktur)
    char k = rfidEgitimOku(rfid1, SS1);
    if (k == '?') k = rfidEgitimOku(rfid2, SS2);
    if (k == '?') k = rfidEgitimOku(rfid3, SS3);
    
    // Eğitim modunda okunan harf sesini doğrudan çalar
    if (k != '?' && k != sonOkunanKup) {
      Serial.print("Egitim Okunan: "); Serial.println(k);
      for(int i = 0; i < 9; i++) {
        if(kartlar[i].harf[0] == k) {
          dfplayer.playMp3Folder(kartlar[i].sesDosyasi);
        }
      }
      sonOkunanKup = k;
      delay(1000);
    } else if(k == '?') {
      sonOkunanKup = '?';
    }
  } 
  else {
    // MOD 2 & MOD 3: TEST MODLARI (Sırayla okuma yapar, Butonla onaylanır)
    
    if (yeniSoruSor) {
      delay(500); 
      int r = (guncelMod == 2) ? random(0, 7) : random(0, 5);
      beklenenCevap = (guncelMod == 2) ? heceSorular[r] : sayiSorular[r];
      
      Serial.print("Soru Soruldu: "); Serial.println(beklenenCevap);
      dfplayer.playMp3Folder((guncelMod == 2) ? heceSesleri[r] : sayiSesleri[r]);
      
      yeniSoruSor = false;
      sira = 1; yuva1 = ""; yuva2 = ""; yuva3 = "";
      Serial.println("Sıralı okuma basladi. 1. yuvaya kartı koyun.");
    }

    // Çalışan sıralı kart okuma adımları
    if (sira == 1) {
      if (yuva1 == "") yuva1 = kartOku(rfid1, SS1, 1);
    } 
    else if (sira == 2) {
      if (yuva2 == "") yuva2 = kartOku(rfid2, SS2, 2);
    } 
    else if (sira == 3) {
      if (yuva3 == "") yuva3 = kartOku(rfid3, SS3, 3);
    }

    // Onaylama Butonuna Basıldığında Cevabı Kontrol Et
    bool currentOnayButton = digitalRead(BTN_ONAY);
    if (lastOnayButtonState == HIGH && currentOnayButton == LOW) {
      
      String cevap = yuva1 + yuva2 + yuva3;
      Serial.print("Kontrol ediliyor... Verilen Cevap: "); Serial.println(cevap);
      
      if (cevap == beklenenCevap) {
        Serial.println("Sonuc: DOGRU!");
        dfplayer.playMp3Folder(dogruCevapSesi);
        delay(dogruYanlisSuresi); 
        yeniSoruSor = true;       
      } else {
        Serial.println("Sonuc: YANLIS! Tekrar deneyin.");
        dfplayer.playMp3Folder(yanlisCevapSesi);
        delay(dogruYanlisSuresi); 
        
        sira = 1; yuva1 = ""; yuva2 = ""; yuva3 = "";
        Serial.println("Yuvalar temizlendi. 1. yuvadan baslayarak tekrar dizin.");
      }
    }
    lastOnayButtonState = currentOnayButton;
  }
}

// SIRALI OKUMA FONKSİYONU
String kartOku(MFRC522 &rfid, int pin, int yuvaNo) {
  digitalWrite(pin, LOW);
  String bulunanHarf = "";
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    for (int i = 0; i < 9; i++) {
      if (memcmp(rfid.uid.uidByte, kartlar[i].uid, 4) == 0) {
        bulunanHarf = kartlar[i].harf;
        Serial.print("Yuva "); Serial.print(yuvaNo); 
        Serial.println(" okundu: " + bulunanHarf);
        dfplayer.playMp3Folder(kartlar[i].sesDosyasi);
        if (sira < 4) sira++; 
        break;
      }
    }
    rfid.PICC_HaltA();
  }
  digitalWrite(pin, HIGH);
  return bulunanHarf;
}

// Eğitim Modu için serbest okuma yapan yardımcı fonksiyon
char rfidEgitimOku(MFRC522 &rfid, int ssPin) {
  digitalWrite(SS1, HIGH); digitalWrite(SS2, HIGH); digitalWrite(SS3, HIGH);
  digitalWrite(ssPin, LOW);
  char sonuc = '?';
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    for (int i = 0; i < 9; i++) {
      if (memcmp(rfid.uid.uidByte, kartlar[i].uid, 4) == 0) { 
        sonuc = kartlar[i].harf[0]; 
        break; 
      }
    }
    rfid.PICC_HaltA(); 
  }
  digitalWrite(ssPin, HIGH);
  return sonuc;
}
