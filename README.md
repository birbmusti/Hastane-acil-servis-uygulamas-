# Acil Servis Yonetim Sistemi
Bu proje, bir hastanenin acil servisinde hasta kaydını yönetmek ve hastaları HL7 formatında listelemek için basit bir C uygulamasıdır. Uygulama, hasta bilgilerini alır, onları aciliyet sırasına göre sıralar ve HL7 formatında çıktı verir.

# Özellikler
1. Hasta Ekleme: Kullanıcı yeni bir hasta ekleyebilir. Hasta adı, yaşı, hastalık durumu, öncelik (aciliyet sırası) gibi bilgileri girebilir. Ayrıca her hasta için bir reçete numarası otomatik olarak oluşturulur.
2. Hasta Listeleme: Sistemde kayıtlı hastalar HL7 formatında listelenir
3. Aciliyet Sırasına Göre Listeleme: Hastalar, aciliyet sırasına göre (önceliklerine göre) sıralanır ve listelenir.
4. Reçete Numarası: Her hasta için benzersiz bir reçete numarası verilir. Reçete numarası, 1000'den başlayarak her yeni hasta için artırılır.

# Kullanılan Teknolojiler
- C Programlama Dili
- HL7 Formatı

# Kullanım
1. Hasta Ekleme
Hasta eklemek için aşağıdaki bilgileri girmeniz gerekmektedir:
Hasta Adı: Hastanın adı.
Yaş: Hastanın yaşı.
Hastalık Durumu: Hastanın acil durumuyla ilgili bilgi.
Öncelik: 1 ile 5 arasında bir değer (1 en yüksek aciliyet, 5 en düşük aciliyet).

2. Hasta Listeleme (HL7 Formatında)
Sistemdeki tüm hastaları HL7 formatında listelemek için bu seçeneği kullanabilirsiniz.

3. Aciliyet Sırasına Göre Listeleme
Hastalar, aciliyet sırasına göre sıralanacak ve ardından HL7 formatında listelenecektir.

4. Çıkış
Programı sonlandırmak için bu seçeneği kullanabilirsiniz.

# Katkıda Bulunma
Bu proje açık kaynaklıdır ve katkıda bulunmaya açıktır. Katkı yapmak için pull request gönderebilirsiniz.
