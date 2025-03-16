# Acil Servis Yonetim Sistemi
Bu proje, bir hastanenin acil servisinde hasta kaydını yönetmek ve hastaları HL7 formatında listelemek için basit bir C uygulamasıdır. Uygulama, hasta bilgilerini alır, onları aciliyet sırasına göre sıralar ve HL7 formatında çıktı verir.

# Özellikler
1. Hasta Ekleme: Kullanıcı yeni bir hasta ekleyebilir. Hasta adı, yaşı, hastalık durumu, öncelik (aciliyet sırası) gibi bilgileri girebilir. Ayrıca her hasta için bir reçete numarası otomatik olarak oluşturulur.
2. Hasta Listeleme: Sistemde kayıtlı hastalar HL7 formatında listelenir
3. Aciliyet Sırasına Göre Listeleme: Hastalar, aciliyet sırasına göre (önceliklerine göre) sıralanır ve listelenir.
4. Reçete Numarası: Her hasta için benzersiz bir reçete numarası verilir. Reçete numarası, 1000'den başlayarak her yeni hasta için artırılır.
