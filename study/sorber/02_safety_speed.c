#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BIG 1000000000UL
uint32_t counter = 0;
pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

void	*count_to_big(void *arg)
{
	for (u_int32_t i = 0; i < BIG; i++)
	{
		// Only one thread can have the lock at a time
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int	main()
{
	pthread_t	t;

	pthread_create(&t, NULL, count_to_big, NULL);
	count_to_big(NULL);
	pthread_join(t, NULL);
	printf("Done. Counter = %u\n", counter);
}

// Time our code using time ./a.out