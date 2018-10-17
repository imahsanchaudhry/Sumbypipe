#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdint.h>

int array[1000];
int Chunk_SIZE = 100;

void intArray(){
	for(int i=0;i<=1000;i++)
		array[i] = i;
}

void * addNumber(void *arg){
	int start = (int)(intptr_t)arg;
	int end = start + Chunk_SIZE;
	int sum = 0;
	for(int i = start;i<=end;i++)
		sum = sum + array[i];
	return ((void*)(intptr_t)sum);
}
int main(){

	int status_t1,status_t2,status_t3,status_t4,status_t5,status_t6,status_t7,status_t8,status_t9,status_t10;
	pthread_t thread_p1,thread_p2,thread_p3,thread_p4,thread_p5,thread_p6,thread_p7,thread_p8,thread_p9,thread_p10;
	
	intArray();
	
	pthread_create(&thread_p1,NULL,addNumber,(void*)(intptr_t)(0 * Chunk_SIZE));
	pthread_create(&thread_p2,NULL,addNumber,(void*)(intptr_t)(1 * Chunk_SIZE));
	pthread_create(&thread_p3,NULL,addNumber,(void*)(intptr_t)(2 * Chunk_SIZE));
	pthread_create(&thread_p4,NULL,addNumber,(void*)(intptr_t)(3 * Chunk_SIZE));
	pthread_create(&thread_p5,NULL,addNumber,(void*)(intptr_t)(4 * Chunk_SIZE));
	pthread_create(&thread_p6,NULL,addNumber,(void*)(intptr_t)(5 * Chunk_SIZE));
	pthread_create(&thread_p7,NULL,addNumber,(void*)(intptr_t)(6 * Chunk_SIZE));
	pthread_create(&thread_p8,NULL,addNumber,(void*)(intptr_t)(7 * Chunk_SIZE));
	pthread_create(&thread_p9,NULL,addNumber,(void*)(intptr_t)(8 * Chunk_SIZE));
	pthread_create(&thread_p10,NULL,addNumber,(void*)(intptr_t)(9 * Chunk_SIZE));
	
	pthread_join(thread_p1,(void**) & status_t1);
	pthread_join(thread_p2,(void**) & status_t2);
	pthread_join(thread_p3,(void**) & status_t3);
	pthread_join(thread_p4,(void**) & status_t4);
	pthread_join(thread_p5,(void**) & status_t5);
	pthread_join(thread_p6,(void**) & status_t6);
	pthread_join(thread_p7,(void**) & status_t7);
	pthread_join(thread_p8,(void**) & status_t8);	
	pthread_join(thread_p9,(void**) & status_t9);
	pthread_join(thread_p10,(void**) & status_t10);	
	
	int result = status_t1+status_t2+status_t3+status_t4+status_t5+status_t6+status_t7+status_t8+status_t9+status_t10;
	printf("Sum = %d", result);
	printf("\n");
	return 0;
}
