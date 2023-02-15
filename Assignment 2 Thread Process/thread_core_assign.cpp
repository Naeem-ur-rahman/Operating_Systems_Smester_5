#define _GNU_SOURCE
#include<iostream>
#include<pthread.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>


using namespace std;

#define handle_error_en(en,msg)\
	do {errno = en; perror(msg);exit(EXIT_FAILURE);} while (0);


void *threadFunction(void *args){
	float x = 1.5f;
	while(1){
		x *= sin(x)/atan(x)*tanh(x)*sqrt(x);
	}
}

int main(){

	cpu_set_t cpuset1;
	CPU_ZERO(&cpuset1);
	CPU_SET(1,&cpuset1);

	cpu_set_t cpuset2;
	CPU_ZERO(&cpuset2);
	CPU_SET(2,&cpuset2);

	pthread_t t1;
	pthread_t t2;

	int t1_op = pthread_create(&t1,NULL,threadFunction,NULL);
	int t2_op = pthread_create(&t2,NULL,threadFunction,NULL);

	int s1 = pthread_setaffinity_np(t1,sizeof(cpu_set_t),&cpuset1);
	if(s1 != 0){
	handle_error_en (s1,"pthread_setaffinity_np,s1");
	}

	int s2 = pthread_setaffinity_np(t1,sizeof(cpu_set_t),&cpuset2);
	if(s2 != 0){
	handle_error_en (s2,"pthread_setaffinity_np,s2");
	}

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);


return 0;
}

