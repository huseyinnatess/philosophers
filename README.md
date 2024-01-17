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
## Kullanılan Hazır Fonksiyonlar

# pthread_create Fonksiyonu

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

Protoip:
```sh
int pthread_join(pthread_t thread, void **retval);
```
| Parametre | Özellikler |
| ------ | ------ |
| *thread | Oluşturulan iş parçacığının id'sini almak için kullanılır. |
| **retval | İş parçacığı tamamlandığında döndürülen değerin saklanacağı adres. İş parçacığı bir değer döndürmese bile bu parametre NULL olarak geçilebilir. |


