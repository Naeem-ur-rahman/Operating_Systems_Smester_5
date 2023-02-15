#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;
void *thread_fun(void *arg);
int main(){
pthread_t mythread; //declare thread
pthread_create(&mythread,NULL,thread_fun,NULL); //create thread
pthread_join(mythread,NULL); //wait for completing thread
cout<<"Now in the main Program !"<<endl;
sleep(1);
cout<<"Ending main"<<endl;
sleep(1);
return 0;
}

void *thread_fun(void *arg){

cout<<"This is Thread"<<endl;
sleep(1);
 int sum=0;
	for (int i=1;i<=100;i++){
  	sum+=i;
}
cout<<"Finnal sum is : "<<sum<<endl;
cout<<"Ending thread"<<endl;
}

