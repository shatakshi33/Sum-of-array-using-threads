/*
 *  pthread_hello.h
 *  
 *
 *  Created by Ankush Mittal on 01/03/15.
 *  Copyright 2015 IIT. All rights reserved.
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000000

time_t t1,t2;
int A[4],i,a[MAX];
long long s1=0,s2=0,s3=0,s4=0;
pthread_t threads1, threads2, threads3, threads4;

void *hello1(void *arg)
{
	
	printf("Hello 1 from node \n");
	//printf("Enter data for thread 1: ");
	for(i=0;i<(MAX/4);i++)
	{
		a[i]=rand();
		s1=s1+a[i];
	}
	return (NULL);
}

void *hello2(void *arg)
{
	
	printf("Hello 2 from node \n");
	pthread_join(threads1,NULL);
	//printf("Enter data for thread 2: ");
	for(i=(MAX/4);i<2*(MAX/4);i++)
	{
		a[i]=rand();
		s2=s2+a[i];
	}
	return (NULL);
}
void *hello3(void *arg)
{
	
	printf("Hello 3 from node \n");
	pthread_join(threads2,NULL);
	//printf("Enter data for thread 3: ");
	for(i=2*(MAX/4);i<3*(MAX/4);i++)
	{
		a[i]=rand();
		s3=s3+a[i];
	}
	return (NULL);
}
void *hello4(void *arg)
{
	
	printf("Hello 4 from node \n");
	pthread_join(threads3,NULL);
	//printf("Enter data for thread 4: ");
	for(i=3*(MAX/4);i<4*(MAX/4);i++)
	{
		a[i]=rand();
		s4=s4+a[i];
	}
	return (NULL);
}

int main(int argc, char* argv[]) {
	
	pthread_attr_t pthread_custom_attr1, pthread_custom_attr2, 		     pthread_custom_attr3, pthread_custom_attr4;
	int *p;
	int temp;

	pthread_attr_init(&pthread_custom_attr1);
	pthread_create(&threads1, &pthread_custom_attr1, hello1, (void *)(p));
	pthread_attr_init(&pthread_custom_attr2);
	pthread_create(&threads2, &pthread_custom_attr2, hello2, (void *)(p));
	pthread_attr_init(&pthread_custom_attr3);
	pthread_create(&threads3, &pthread_custom_attr3, hello3, (void *)(p));
	pthread_attr_init(&pthread_custom_attr4);
	pthread_create(&threads4, &pthread_custom_attr4, hello4, (void *)(p));
	
	
	(void) time(&t1);
	pthread_join(threads4,NULL);
	(void) time (&t2);
	printf("\n\t\tSum = %lld\n",(s1+s2+s3+s4));
	printf("Time= %2f",(double) t2-t1);
	
}
