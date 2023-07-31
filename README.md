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

## File Descriptor (fd) nedir?
"file descriptor" (dosya tanımlayıcısı), dosyalara veya diğer giriş/çıkış kaynaklarına erişmek için kullanılan bir tamsayı değeridir. Dosya tanımlayıcısı, işletim sistemi tarafından oluşturulan bir işaretçi gibidir,

Dosya tanımlayıcıları, işletim sisteminde açık olan her dosya için benzersiz bir numaralandırmaya sahiptir. Örneğin, UNIX ve Linux sistemlerinde, 0, 1 ve 2 numaralı dosya tanımlayıcıları özel olarak aşağıdaki şekilde atanır:

-   0: Standart giriş (stdin) - Klavyeden okuma için kullanılır.
-   1: Standart çıkış (stdout) - Ekran yazdırma için kullanılır.
-   2: Standart hata (stderr) - Hata mesajlarını göndermek için kullanılır.

Ayrıca, 3 ve sonraki numaralar, açık olan diğer dosyalar için atanır. Bu dosya tanımlayıcıları, `open()` veya `fopen()` gibi dosya açma işlevleri kullanılarak elde edilir. Dosya tanımlayıcıları, `int` türünden değişkenlerde saklanır.

## Fd icin open fonksiyonu nasil kullanilir?
Fonksiyonun prototipi şu şekildedir:
```c
int open(const char *path, int flags, mode_t mode);` 
```
Burada, `path` parametresi açılacak dosyanın yolu ve adını içeren bir karakter dizisidir. `flags` parametresi açma modunu belirlemek için kullanılır ve hangi türde dosya erişimi yapılacağını belirtir. `mode` parametresi ise yeni bir dosya oluşturulduğunda izinlerin belirlenmesi için kullanılır (bu parametre sadece dosya oluşturulduğunda önemlidir).

`open()` işlevi, bir dosya tanımlayıcısı (file descriptor) döndürür. Dosya tanımlayıcısı, dosyaya erişim ve dosya üzerinde işlem yapmak için kullanılır. Eğer işlem başarısız olursa, -1 değeri döndürür.

---
 **en sık kullanılan `flags` parametreleri ve açıklamaları:**

1.  `O_RDONLY`: Dosyayı sadece okuma modunda açar. Dosyanın içeriği değiştirilemez, sadece okunabilir.
    
2.  `O_WRONLY`: Dosyayı sadece yazma modunda açar. Dosyanın içeriği okunamaz, sadece değiştirilebilir.
    
3.  `O_RDWR`: Dosyayı hem okuma hem de yazma modunda açar. Dosya içeriğini okuyabilir ve değiştirebilirsiniz.
    
4.  `O_CREAT`: Eğer dosya yoksa, yeni bir dosya oluşturur. Bu bayrak, dosya açma işleminin yeni bir dosya oluşturma işlemi için kullanılacağını belirtir.
    
5.  `O_TRUNC`: Dosya varsa, içeriğini temizler (sıfırlar). Dosyayı açarken içeriği silmek ve dosyayı boşaltmak için kullanılır.
    
6.  `O_APPEND`: Dosya varsa, dosyanın sonuna ekler. Yani, her yazma işlemi dosyanın sonuna eklenir, varolan içeriği değiştirmez.
    
7.  `O_EXCL`: Dosya varsa, hata döndürür. Bu bayrak, `O_CREAT` bayrağıyla birlikte kullanılır ve eğer dosya zaten varsa hata döndürür.
    
8.  `O_TRUNC | O_CREAT`: Eğer dosya varsa içeriğini siler, eğer dosya yoksa yeni bir dosya oluşturur. Bu bayrak, dosya içeriğini sıfırlayarak mevcut dosyayı kullanmak için kullanılır.

```c
#include <fcntl.h>  
#include <unistd.h>  
int  main() { 
	int fd; 
// Dosyayı yazma modunda (write-only) aç 
	fd = open("example.txt", O_WRONLY); 
	if (fd == -1) { 
		perror("Dosya acilamadi"); 
		return  1; 
	} 
// Dosyayı kapat 
	close(fd); 
	return  0; 
	}
```
