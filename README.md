# Notlar

- Bu örnek kodda pthread_create fonksiyonu ile bir thread (yardımcı iş parçacığı) oluşturulur.

```sh
#include <pthread.h>
#include <stdio.h>

void	*my_ThreadFun(void *vargp)
{
	printf("Bu bir thread örneğidir.\n");
	return (NULL);
}

int	main(void)
{
	pthread_t thread_id;
	printf("Ana işlem başlıyor.\n");
	pthread_create(&thread_id, NULL, my_ThreadFun, NULL);
	pthread_join(thread_id, NULL);
	printf("Ana işlem bitti.\n");
	return (0);
}
```
## pthread_create Fonksiyonu

```sh
Protoip:
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
```

| Parametre | Özellikler |
| ------ | ------ |
| *thread | Oluşturulan iş parçacığının id'sini almak için kullanılır. |
| *attr | Oluşturulan iş parçacığının özniteliklerini belirtmek için kullanılır. Default olarak NULL şeklinde belirtilir. Böylece varsayılan öznitelikler kullanılır. |
| *start_rutine | Çalıştırılacak olan işlev verilir. void* türünden parametre alır |
| *arg | Çalıştırılacak işleve verilecek parametredir. |

## pthread_join Fonskiyonu

```sh
Protoip:
int pthread_join(pthread_t thread, void **retval);
```
| Parametre | Özellikler |
| ------ | ------ |
| *thread | Oluşturulan iş parçacığının id'sini almak için kullanılır. |
| **retval | İş parçacığı tamamlandığında döndürülen değerin saklanacağı adres. İş parçacığı bir değer döndürmese bile bu parametre NULL olarak geçilebilir. |
