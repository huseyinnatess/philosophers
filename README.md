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
