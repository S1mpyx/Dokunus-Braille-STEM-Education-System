# 📚 Dokunuş – Dijital İnteraktif Kabartma Yazı Eğitim Seti

> **TEKNOFEST 2026 Projesi**  
> **Synapse Takımı**

---

# 👋 Synapse Takımı Hakkında

Merhaba!

Biz **Synapse Takımı** olarak teknolojiyi toplumsal faydaya dönüştürmeyi hedefleyen bir öğrenci ekibiyiz.

Bu proje, görme engelli bireylerin Braille (Kabartma Yazı) eğitimini daha erişilebilir, bağımsız ve ekonomik hale getirmek amacıyla geliştirilmiştir.

Elektronik, yazılım ve üç boyutlu tasarım alanlarını bir araya getirerek öğrencilerin öğretmen veya veli desteğine daha az ihtiyaç duyacağı, sesli geri bildirim sağlayan interaktif bir eğitim sistemi tasarladık.

Amacımız yalnızca bir prototip geliştirmek değil; eğitimde fırsat eşitliğine katkı sağlayabilecek, geliştirilebilir ve ticarileştirilebilir yerli bir ürün ortaya koymaktır.

---

# 👥 Takımımız

## 👨‍💻 Yiğit Dağlı

- Elektronik sistem tasarımı
- Arduino programlama
- Devre kurulumu
- RFID sisteminin geliştirilmesi
- 3B modelleme (Blender)
- Mekanik tasarım
- Prototip üretimi
- Donanım testleri

---

## 👨‍💻 Alperen Arda

**Takım Kaptanı**

- Literatür araştırması
- Yazılım geliştirme
- Ses kayıtlarının hazırlanması
- SD kart içeriklerinin oluşturulması
- Proje dokümantasyonu
- Sunum hazırlanması

---

## 👩‍🏫 Danışman Öğretmen

**Ceren Gezer**

Proje süreci boyunca teknik, akademik ve organizasyonel konularda ekibimize rehberlik etmiştir.

---

# 📖 Proje Hakkında

Dokunuş, görme engelli öğrencilerin Braille alfabesini ve temel sayıları daha kolay öğrenebilmesi amacıyla geliştirilmiş interaktif bir eğitim setidir.

Mevcut eğitim sürecinde öğrenciler çoğu zaman öğretmen veya aile desteğine ihtiyaç duymaktadır. Ayrıca piyasada bulunan elektronik eğitim cihazlarının büyük bölümü ithal olup oldukça yüksek maliyetlidir.

Dokunuş, öğrencinin yaptığı çalışmayı anında değerlendirerek doğru veya yanlış olduğuna dair sesli geri bildirim verir. Böylece öğrenci istediği zaman kendi başına tekrar yapabilir.

---

# 🎯 Projenin Amacı

- Görme engelli öğrencilerin bağımsız öğrenmesini desteklemek
- Braille eğitimini daha erişilebilir hale getirmek
- Öğretmen ve aile üzerindeki yükü azaltmak
- Yerli ve düşük maliyetli bir eğitim sistemi geliştirmek
- Eğitimde fırsat eşitliğine katkı sağlamak

---

# ❓ Çözülen Problem

Braille öğrenme süreci;

- Yoğun tekrar gerektirir.
- Sürekli eğitmen desteğine ihtiyaç duyabilir.
- Öğrenci yaptığı çalışmanın doğru olup olmadığını anında öğrenemeyebilir.
- Elektronik eğitim cihazları yüksek maliyetlidir.

Dokunuş bu problemlere düşük maliyetli ve taşınabilir bir çözüm sunmaktadır.

---

# ⚙️ Sistem Nasıl Çalışır?

1. Öğrenci çalışma modunu seçer.
2. Braille küplerini RFID okuyucular üzerine yerleştirir.
3. RFID etiketleri algılanır.
4. Arduino doğru dizilimi kontrol eder.
5. DFPlayer Mini üzerinden sesli geri bildirim verilir.
6. Öğrenci doğru cevaba ulaşıncaya kadar çalışmaya devam eder.

---

# 📚 Çalışma Modları

## 🔹 Harf Öğrenme Modu

Küp okutulduğunda;

- Harf okunur.
- O harfle başlayan bir hece söylenir.
- O harfle başlayan bir kelime söylenir.

---

## 🔹 Hece Testi

Sistem rastgele bir hece seçer.

Öğrenci doğru harfleri sıralamaya çalışır.

Yanlış cevaplarda doğru dizilime ulaşılıncaya kadar aynı soru tekrar edilir.

---

## 🔹 Sayı Testi

Sistem rastgele üç basamağa kadar sayı oluşturur.

Öğrenci doğru rakamları sıralar.

Doğru cevap sesli olarak onaylanır.

---

# 🛠️ Kullanılan Donanımlar

- Arduino Uno
- 3 × MFRC522 RFID Modülü
- DFPlayer Mini
- Hoparlör
- Push Button
- NFC/RFID Etiketleri
- AMS1117 Voltaj Regülatörü
- Kondansatörler
- 3B Baskı Parçaları

---

# 💻 Kullanılan Yazılımlar

- Arduino IDE
- C++
- Blender

---

# 🖨️ Prototip

Prototipin;

- Elektronik devresi,
- Mekanik tasarımı,
- Yazılımı,
- Braille küpleri,
- Ana gövdesi

Synapse Takımı tarafından geliştirilmiştir.

---

# 💰 Maliyet

| Ürün | Yaklaşık Maliyet |
|------|-----------------:|
| Dokunuş Prototipi | ≈ 1.400 TL |
| Benzer İthal Ürünler | 30.000 – 60.000 TL |

---

# 🎯 Hedef Kitle

- 6–12 yaş arası görme engelli öğrenciler
- Aileler
- Özel eğitim öğretmenleri
- Kaynaştırma sınıfları
- Rehabilitasyon merkezleri
- Görme engelli dernekleri
- Vakıflar
- Millî Eğitim Bakanlığına bağlı eğitim kurumları

---

# 📈 Ticarileştirme Potansiyeli

Dokunuş;

- Yerli üretime uygundur.
- Modüler yapıya sahiptir.
- Düşük maliyetlidir.
- Kolay tamir edilebilir.
- Seri üretime uygundur.

Gelecekte;

- Mobil uygulama
- Öğrenci takip sistemi
- Öğretmen paneli
- Daha fazla RFID okuyucu desteği
- Yeni eğitim modülleri

eklenmesi planlanmaktadır.

---

# SWOT Analizi

## ✅ Güçlü Yönler

- Yerli üretim
- Düşük maliyet
- Türkçe uyumluluğu
- Modüler tasarım
- Kolay tamir edilebilir yapı
- Taşınabilir sistem

## ⚠️ Zayıf Yönler

- İlk prototipte en fazla üç harfli kelimeler oluşturulabilmektedir.
- Kelime havuzu geliştirilmeye açıktır.

## 🚀 Fırsatlar

- Türkiye'de benzer düşük maliyetli ürün bulunmaması
- Eğitim kurumlarında yaygın kullanılabilme potansiyeli
- Açık kaynak olarak geliştirilebilmesi

## ⚡ Tehditler

- Küçük yaş grubundan kaynaklanan fiziksel darbe riski
- Sıvı teması
- Elektronik bileşen maliyetlerindeki değişimler

---

# 📜 Lisans

Bu proje TEKNOFEST kapsamında eğitim ve araştırma amacıyla geliştirilmiştir.

---

# ❤️ Teşekkür

Bu projeye katkı sağlayan danışman öğretmenimize, takım arkadaşlarımıza ve proje sürecinde destek veren herkese teşekkür ederiz.

---

⭐ **Synapse Takımı**  
**TEKNOFEST 2026**

Русский/Rusça

# 📚 Докунуш — Интерактивный цифровой учебный комплект по шрифту Брайля

> **Проект TEKNOFEST 2026**  
> **Команда Synapse**

---

# 👋 О нашей команде

Здравствуйте!

Мы — команда **Synapse**, объединяющая учеников, которые стремятся применять современные технологии для решения социальных задач.

Проект **«Докунуш»** был разработан с целью сделать обучение шрифту Брайля для слабовидящих и незрячих детей более доступным, самостоятельным и эффективным.

Объединив электронику, программирование и 3D-моделирование, мы создали интерактивную обучающую систему, способную давать голосовую обратную связь и помогать ученикам заниматься без постоянной помощи преподавателя.

Наша цель — не только создать прототип, но и разработать отечественный, доступный и масштабируемый образовательный продукт.

---

# 👥 Команда проекта

## 👨‍💻 Йигит Даглы

- Разработка электронной части проекта
- Программирование Arduino
- Сборка электронных схем
- Разработка RFID-системы
- 3D-моделирование (Blender)
- Механическое проектирование
- Изготовление прототипа
- Тестирование аппаратной части

---

## 👨‍💻 Альперен Арда

**Капитан команды**

- Анализ научной литературы
- Разработка программного обеспечения
- Подготовка аудиоматериалов
- Создание содержимого SD-карты
- Подготовка проектной документации
- Подготовка презентации

---

## 👩‍🏫 Руководитель проекта

**Джерен Гезер**

Оказывала научное и техническое руководство на всех этапах разработки проекта.

---

# 📖 О проекте

**«Докунуш»** — это интерактивный учебный комплект, предназначенный для обучения незрячих детей шрифту Брайля и основам счёта.

Во многих случаях обучение требует постоянного участия преподавателя или родителей. Кроме того, большинство электронных обучающих устройств являются импортными и имеют высокую стоимость.

Разработанная нами система позволяет автоматически проверять ответы ученика и мгновенно сообщать о результате с помощью голосовой обратной связи.

Таким образом ученик может самостоятельно выполнять упражнения и закреплять материал.

---

# 🎯 Цель проекта

Проект направлен на:

- развитие самостоятельного обучения;
- облегчение изучения шрифта Брайля;
- поддержку инклюзивного образования;
- снижение зависимости от преподавателя;
- создание доступной отечественной образовательной системы.

---

# ❓ Решаемая проблема

При изучении шрифта Брайля учащиеся сталкиваются со следующими трудностями:

- необходимость постоянной помощи преподавателя;
- отсутствие мгновенной проверки правильности ответа;
- высокая стоимость существующих электронных устройств.

Проект «Докунуш» предлагает доступное и мобильное решение этих проблем.

---

# ⚙️ Принцип работы

1. Пользователь выбирает режим обучения.
2. Кубики Брайля размещаются на RFID-считывателях.
3. RFID-метки распознаются системой.
4. Arduino анализирует правильность ответа.
5. DFPlayer Mini воспроизводит голосовую обратную связь.
6. Ученик продолжает обучение до получения правильного результата.

---

# 📚 Режимы работы

## 🔹 Изучение букв

После считывания кубика система произносит:

- букву;
- слог;
- слово, начинающееся с данной буквы.

---

## 🔹 Проверка слогов

Система случайным образом выбирает слог.

Ученик составляет его с помощью кубиков.

При неправильном ответе вопрос повторяется до правильного выполнения.

---

## 🔹 Проверка чисел

Система случайным образом озвучивает числа до трёх разрядов.

Ученик должен составить правильную последовательность цифр.

---

# 🛠 Используемое оборудование

- Arduino Uno
- 3 модуля RFID MFRC522
- DFPlayer Mini
- Динамик
- Кнопки управления
- RFID/NFC-метки
- Стабилизатор напряжения AMS1117
- Конденсаторы
- Детали, изготовленные на 3D-принтере

---

# 💻 Используемое программное обеспечение

- Arduino IDE
- C++
- Blender

---

# 🖨 Прототип

Командой Synapse были самостоятельно разработаны:

- электронная схема;
- программное обеспечение;
- корпус устройства;
- кубики Брайля;
- механическая конструкция.

---

# 💰 Стоимость

| Наименование | Стоимость |
|--------------|-----------:|
| Прототип «Докунуш» | ≈ 1400 турецких лир |
| Импортные аналоги | 30 000–60 000 турецких лир |

---

# 🎯 Целевая аудитория

- незрячие дети 6–12 лет;
- родители;
- учителя специального образования;
- инклюзивные классы;
- реабилитационные центры;
- школы;
- общественные организации и фонды.

---

# 📈 Потенциал коммерциализации

Проект обладает следующими преимуществами:

- отечественная разработка;
- модульная конструкция;
- низкая стоимость производства;
- простота ремонта;
- возможность серийного производства.

В дальнейшем планируется добавить:

- мобильное приложение;
- систему отслеживания успеваемости;
- панель преподавателя;
- поддержку большего количества RFID-считывателей;
- новые образовательные режимы.

---

# SWOT-анализ

## ✅ Сильные стороны

- отечественная разработка;
- низкая стоимость;
- поддержка турецкого языка;
- модульная конструкция;
- ремонтопригодность;
- портативность.

## ⚠️ Слабые стороны

- текущий прототип поддерживает слова длиной до трёх букв;
- словарный запас может быть расширен.

## 🚀 Возможности

- отсутствие аналогичных доступных решений в Турции;
- высокий потенциал внедрения в образовательные учреждения;
- возможность развития проекта как открытого программного обеспечения.

## ⚡ Угрозы

- механические повреждения при использовании детьми;
- воздействие влаги;
- изменение стоимости электронных компонентов.

---

# 📜 Лицензия

Проект разработан исключительно в образовательных и исследовательских целях в рамках конкурса **TEKNOFEST 2026**.

---

# ❤️ Благодарности

Выражаем искреннюю благодарность нашему научному руководителю, всем членам команды и каждому, кто поддержал нас в процессе разработки проекта.

---

⭐ **Команда Synapse**  
**TEKNOFEST 2026**
