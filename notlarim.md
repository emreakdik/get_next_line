## Buffer Nedir?
C dilinde, buffer (arabellek) bir bellek alanıdır. Genellikle, veri okuma veya yazma işlemlerinde kullanılır. Bir buffer, verileri geçici olarak depolamak için kullanılır ve daha sonra diğer işlemlerde kullanılmak üzere veri işlemeye yönlendirilir.

Buffer kullanımı veri işlemleri sırasında hız ve verimliliği arttırmak için kullanılır. Örneğin, bir dosyadan veri okurken, buffer kullanarak okunan veri arabellekte tutulur ve daha sonra işlem yapılacak diğer yere taşınır. Bu işlem, dosyayı sürekli olarak açık tutmak yerine, buffer kullanarak verileri tek seferde okumayı sağlar ve bu da hız ve verimliliği arttırır.

C dilinde buffer kullanmak için `malloc()` veya `calloc()` gibi fonksiyonlar kullanılabilir, veya direkt olarak isim verilmeden tanımlanabilir.
## Read()
C dilinde, `read()` fonksiyonu, bir dosyadan veya sistem kaynaklarından veri okumak için kullanılır. Bu fonksiyon, `unistd.h` kütüphanesinde tanımlıdır.

`read()` fonksiyonunun ilk parametresi, okunacak dosyanın file descriptor'ıdır. File descriptor, sistem tarafından atanan bir dosya için benzersiz bir tanımlayıcıdır. İkinci parametresi, okunacak verinin yer alacağı buffer'dır. Üçüncü parametresi ise okunacak verinin maksimum boyutudur.

- Okunacak boyut eger 0 ise, fonksiyon 0 dondurur.
- Eğer okuma işlemi başarılı olduysa, geri dönen değer okunan verinin gerçek boyutudur. 
- Eğer okuma işlemi başarısız olduysa, fonksiyon -1 değerini döndürür. 
- Eger okuma islemi basarili olduysa ve daha fazla okunacak byte kalmadiysa, fonksiyon dosyanin bittigini gostermek adina 0 dondurur.

Not: Aslinda dosya icerikleri grafiksel olarak satir satir gorunse de, arkaplan da oyle degildir. Her bir satirin sonunda /n vardir ve metin hemen pesinden devam eder. O yuzden read fonksiyonunun okurken alt satira gecme gibi bir durumu yoktur. Yani read fonksiyonu metin'i bizim gibi satir satir gormez tek satir olarak gorur fakat aralarda /n ile gorur.

## Statik Degiskenler

Kisaca, tuttugu degeri, baska fonksiyonlara gecse de, program bitse de saklayan degiskenlerdir.

C dilinde, statik değişkenler, programın çalışması sırasında bellekte yer ayrılarak, programın çalışma süresi boyunca saklanır. Bu değişkenlerin değerleri programın sona ermesinden sonra da kalır. Bu nedenle, bir sonraki program çalışması sırasında, statik değişkenlerin değerleri daha önceki çalışması sırasında kullanılmış değerlerdir.

Ayrıca, statik değişkenler sadece fonksiyon veya global alanda tanımlanabilir. ve global alanda tanımladığınızda programın tüm bölümlerinde erişilebilir, fonksiyon içerisinde tanımladığınızda sadece o fonksiyon içerisinde erişilebilir.

- Statik değişkenler, ilk değer ataması yapılmamışsa, varsayılan olarak 0 olarak başlatılır.
- Statik bir değişken işaretçi olarak tanımlanırsa, varsayılan olarak null pointer (0) olarak başlatılır. Yani, işaretçi statik olarak tanımlanmış bir değişkene işaret etmiyor.

Bu degiskenleri get_next_line projesinde girdi bolunmelerindeki kaybolabilecek, arada kalabilecek verileri kaybetmemek icin kullaniyoruz.

## Open Komutlari
C dilinde, "open" komutunu kullanmak için "fcntl.h" veya "sys/stat.h" başlık dosyalarını dahil etmeniz gerekir. Bu başlık dosyaları, dosya işlemleri için gerekli olan fonksiyonları içerir. Örneğin, aşağıdaki kod parçacığı, "myfile.txt" dosyasını okuma modunda açar:

```c
#include <fcntl.h>
#include <sys/stat.h>

int fd;

fd = open("myfile.txt", O_RDONLY);
if (fd == -1) {
    // Dosya açma hatası
} else {
    // Dosya başarıyla açıldı
}
```

Bu örnekte, dosya adı "myfile.txt" ve mod O_RDONLY (sadece okuma) olarak belirlenmiştir. Ayrıca, dosya açılırken fd değişkenine atanır, bu değişken dosya işlemleri için kullanılacak dosya tanıtıcısıdır.

"open" fonksiyonu, iki temel parametre alır:

1.  **path**: Bu parametre, açılmak istenen dosya veya klasörün yolunu içerir. Bu yol, absolut veya relatif olarak belirlenebilir.
    
2.  **flags**: Bu parametre, dosyanın nasıl açılacağını belirler. Örneğin, dosya sadece okunacak mı yoksa yazılacak mı, eğer dosya yoksa oluşturulacak mı, vb. Bu parametre için aşağıdaki değerler kullanılabilir:
    
    -   O_RDONLY: Dosya sadece okunur.
    -   O_WRONLY: Dosya sadece yazılır.
    -   O_RDWR: Dosya hem okunur hem yazılır.
    -   O_APPEND: Dosyaya yazarken her zaman sonuna ekler.
    -   O_CREAT: Dosya yoksa oluşturulur.
    -   O_TRUNC: Dosya açıldığında içeriği silinir.
    -   O_EXCL: Dosya zaten var ise hata verir.

Ornek bir kullanim: 
open("myfile.txt", O_RDWR | O_CREAT | O_TRUNC | O_EXCL, S_IRUSR | S_IWUSR);