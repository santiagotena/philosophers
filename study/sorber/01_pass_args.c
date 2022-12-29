#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Pass an argument in main and return a value
void	*myturn(void *arg)
{
	int	*iptr = (int *)malloc(sizeof(int));

	*iptr = 5;
	for (int i = 0; i < 8; i++)
	{
		sleep(1);
		printf("My Turn! %d %d\n", i, *iptr);
		(*iptr)++;
	}
	return (iptr);
}

void	yourturn()
{
	for (int i = 0; i < 3; i++)
	{
		sleep(2);
		printf("Your Turn! %d\n", i);
	}
}

int main()
{
	pthread_t	newthread;
	int			*result;

	// Pass v as an argument:
	pthread_create(&newthread, NULL, myturn, NULL);
	yourturn();
	// Wait until a specific thread is over:
	pthread_join(newthread, (void *)&result);
	printf("thread's done: *result=%d\n", *result);
	free(result);
}

/////////////

// Pass an argument in main (v)
// void	*myturn(void *arg)
// {
// 	int	*iptr = (int *)arg;

// 	for (int i = 0; i < 8; i++)
// 	{
// 		sleep(1);
// 		printf("My Turn! %d %d\n", i, *iptr);
// 		(*iptr)++;
// 	}
// 	return (NULL);
// }

// void	yourturn()
// {
// 	for (int i = 0; i < 3; i++)
// 	{
// 		sleep(2);
// 		printf("Your Turn! %d\n", i);
// 	}
// }

// int main()
// {
// 	pthread_t	newthread;
// 	int			v;

// 	v = 5;
// 	// Pass v as an argument:
// 	pthread_create(&newthread, NULL, myturn, &v);
// 	yourturn();
// 	// Wait until a specific thread is over:
// 	pthread_join(newthread, NULL);
// 	printf("thread's done v=%d\n", v);
// }
