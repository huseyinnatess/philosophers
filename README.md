# Notlar

# Thread (İş parçacığı)

- Thread bir işlemi birden fazla parçaya ayırıp bu parçaları aynı anda çalıştırmak için kullanılır. Böylece işlem daha hızlı gerçekleşir.
- Bu örnek kodda pthread_create fonksiyonu ile bir thread (yardımcı iş parçacığı) oluşturulur.

```sh
#include <pthread.h>
#include <stdio.h>

// Oluşturulan Thread Fonksiyonu (İş parçacığı).
void	*my_ThreadFun(void *vargp)
{
	printf("Bu bir thread örneğidir.\n");
	return (NULL);
}

int	main(void)
{
	pthread_t thread_id;
	printf("Ana işlem başlıyor.\n");
	pthread_create(&thread_id, NULL, my_ThreadFun, NULL); // Thread Oluşturma.
	pthread_join(thread_id, NULL); // Thread'in tamamlanmasını bekleme.
	printf("Ana işlem bitti.\n");
	return (0);
}
```
# Kullanılan Hazır Fonksiyonlar

## pthread_create Fonksiyonu

Thread oluşturmak için kullanılır.

Protoip:
```sh
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
```
| Parametre | Özellikler |
| ------ | ------ |
| *thread | Oluşturulan iş parçacığının id'sini almak için kullanılır. |
| *attr | Oluşturulan iş parçacığının özniteliklerini belirtmek için kullanılır. Default olarak NULL şeklinde belirtilir. Böylece varsayılan öznitelikler kullanılır. |
| *start_rutine | Çalıştırılacak olan işlev verilir. void* türünden parametre alır |
| *arg | Çalıştırılacak işleve verilecek parametredir. |

- Örnek olarak parametre göndermek için:

```sh
#include <pthread.h>
#include <stdio.h>

void	*my_ThreadFun(void *str)
{    
    char *str2;
    
    str2 = str;
    printf("%s\n", str2);
    return (NULL);
}

int	main(void)
{
    pthread_t thread_id1; // İki adet thread tanımlıyoruz.
    pthread_create(&thread_id1, NULL, my_ThreadFun, "Merhaba"); // İlk thread'i oluşturuyoruz.
    pthread_join(thread_id1, NULL); // Threadlerin bitmesini bekleme.
	return (0);
}
```
- Parametreli kullanım bu şekildedir.

## pthread_join Fonskiyonu

Oluşturulan thread tamamlanana kadar ilgili fonksiyonu bekletir.

Protoip:
```sh
int pthread_join(pthread_t thread, void **retval);
```
| Parametre | Özellikler |
| ------ | ------ |
| *thread | Oluşturulan iş parçacığının id'sini almak için kullanılır. |
| **retval | İş parçacığı tamamlandığında döndürülen değerin saklanacağı adres. İş parçacığı bir değer döndürmese bile bu parametre NULL olarak geçilebilir. |

# Mutex

- Bir işlem tarafından kullanılan kaynakların diğer işlemler tarafından aynı anda kullanılmaını engeller böylece çakışmalara engel olur.

```sh
#include <pthread.h>
#include <stdio.h>

int x = 0; // Global bir değişken.
pthread_mutex_t mutex; // Mutex nesnesi.

void	*my_ThreadFun(void *vargp)
{
    pthread_mutex_lock(&mutex); // Mutex'i kilitliyoruz.
    x++; // Kritik nokta. X değerini arttırıyoruz.
    pthread_mutex_unlock(&mutex); // Mutex kilidini açıyoruz.
    return (NULL);
}

int	main(void)
{
    pthread_t thread_id1, thread_id2; // İki adet thread tanımlıyoruz.
    pthread_mutex_init(&mutex, NULL); // Mutex'i başlatıyoruz.
    pthread_create(&thread_id1, NULL, my_ThreadFun, NULL); // İlk thread'i oluşturuyoruz.
    pthread_create(&thread_id2, NULL, my_ThreadFun, NULL); // İkinci thread'i oluşturuyoruz.
    pthread_join(thread_id1, NULL); // Threadlerin bitmesini bekleme.
    pthread_join(thread_id2, NULL); // Threadlerin bitmesini bekleme.
    pthread_mutex_destroy(&mutex);
    printf("x değeri: %d\n", x);
	return (0);
}
```
- Bu örnekte ilk thread çalışmaya başlayınca mutex'i kilitleyip x değerini bir arttırır. Mutex kilitli olduğu müddetçe diğer işlemler kilit açılana kadar bekler. En son kilit açılır ve işlemler devam eder.
- Daha iyi anlamak isteyenler printf'i ilk thread'in çalıştığı fonkisyonun altına alıp (pthread_join) mutex unlock fonksiyonunu silip test edebilir. Program kapanmayıp kilit açılana kadar bekleyecektir.

## pthread_mutex_init() Fonksiyonu

- Mutex nesnesini başlatır.

Prototip:
```sh
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
```
| Parametre | Özellikler |
| ------ | ------ |
| *mutex | İnit edilecek mutex nesnesi |
| *attr | Mutexin özelliklerini belirler. Default olarak NULL'dır. Varsayılan özellikleri kullanır. |

## pthread_mutex_lock() Fonksiyonu

- Mutex'i kilitler.

Prototip:
```sh
int pthread_mutex_lock(pthread_mutex_t *mutex);
```
| Parametre | Özellikler |
| ------ | ------ |
| *mutex | Kilitlenecek mutex. |

## pthread_mutex_unlock Fonksiyonu

- Mutex'in kilidini açar

Prototip:
```sh
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```
| Parametre | Özellikler |
| ------ | ------ |
| *mutex | Kilidi kaldırılacak mutex. |

# Ekstralar

## gettimeofday() Fonksiyonu

- UNIX benzeri işletim sistemlerinde sistem saatini döndürür. Bu fonksiyon genellikle zaman ölçümü ve zaman damgası (timestamp) oluşturma gibi uygulamalarda kullanılır.

```sh
#include <stdio.h>
#include <sys/time.h>

int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("Sistem saati: %ld s %d us\n", tv.tv_sec, tv.tv_usec);
    return (0);
}
```
Bu kodda sistem saati alınmış ve tv yapısına aktarılmıştır. Daha sonra saniye ve mikrosaniye'ye çevrilerek ekrana yazdırılmıştır.

Prototip:
```sh
#include <sys/time.h>

int gettimeofday(struct timeval *tv, struct timezone *tz);

```
| Parametre | Özellikler |
| ------ | ------ |
| *tv | Sistem saatini tutan yapı. |
| *tz | Obsolet (artık kullanılmayan) bir parametredir ve genellikle NULL olarak atanır.|

# Kullanılan Argümanlar

## Kullanıcı Girişi

| Parametre                                           | Açıklama                                                                                      |
| -------------------------------------------------- | -------------------------------------------------------------------------------------------- |
| `number_of_philosophers`                           | Filozof sayısı ve aynı zamanda çatal sayısı.                                                  |
| `time_to_die` (milisaniye cinsinden)               | Eğer bir filozof, son yemeğinin veya simulasyonun başlangıcından bu yana geçen `time_to_die` milisaniye içinde yemek yeme işlemine başlamazsa, açlıktan ölür. |
| `time_to_eat` (milisaniye cinsinden)               | Bir filozofun yemek yemesi için geçen süre. Bu süre içinde iki çatalı tutması gerekir.         |
| `time_to_sleep` (milisaniye cinsinden)             | Bir filozofun uyuma süresi.                                                                   |
| `number_of_times_each_philosopher_must_eat` (opsiyonel) | Eğer tüm filozoflar en az `number_of_times_each_philosopher_must_eat` kez yemişse, simulasyon durur. Belirtilmemişse, simulasyon bir filozofun ölümüyle sona erer. |

