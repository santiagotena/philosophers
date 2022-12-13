#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void	*myturn(void *arg)
{
	while (1)
	{
		sleep(1);
		printf("My Turn!\n");
	}
	return (NULL);
}

void	yourturn()
{
	while (1)
	{
		sleep(2);
		printf("Your Turn!\n");
	}
}

int main()
{
	pthread_t	newthread;

	pthread_create(&newthread, NULL, myturn, NULL);
	yourturn();
	pthread_join(&newthread, NULL); //Wait until a specific thread is over
}