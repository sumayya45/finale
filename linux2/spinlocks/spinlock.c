#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

#define NUMBER_OF_THREADS 42
#define NUMBER_OF_OPERATIONS 100000

pthread_spinlock_t spinlock;
int balance=0;

void *deposit(void *arg)
{
	int a=0;
	for(a=0;a<=NUMBER_OF_OPERATIONS; a++)
	{
		pthread_spin_lock(&spinlock);
		balance++;
		pthread_spin_unlock(&spinlock);
		printf("the no of balance are %d\n",balance);
	}
	return NULL;
}
void *withdraw(void *arg)
{	
	int a=0;
	for( a=0; a<=NUMBER_OF_OPERATIONS; a++)
	{
		pthread_spin_lock(&spinlock);
		balance--;
		pthread_spin_unlock(&spinlock);
	}
	return NULL;
}
int main()
{
	pthread_t threads[NUMBER_OF_THREADS];
	pthread_spin_init(&spinlock,0);
	int i;
	for(i=0; i<NUMBER_OF_THREADS/2; i++)
	{
		if(pthread_create(&threads[i],NULL,deposit,NULL)!=0)
		{
			perror("failed to create deposit thread");
	
			return 1;
		}
	}
	for(i=0; i<NUMBER_OF_THREADS/2; i++)
	{
		if(pthread_create(&threads[i],NULL,withdraw,NULL)!=0)
		{
			perror("failed to create withdrawl thread");
			return 1;
		}
	}
	for(i=0;i<NUMBER_OF_THREADS;i++){
		pthread_join(threads[i],NULL);
	}
pthread_spin_destroy(&spinlock);
printf("the final balnce is %d\n",balance);

return 0;
}
