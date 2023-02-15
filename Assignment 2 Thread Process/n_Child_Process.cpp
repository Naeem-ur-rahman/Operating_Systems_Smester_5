#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main(){
int n;
cout <<"Enter the no Child process : ";cin>>n;
int id;
for(int j =1;j<=n;j++){
	if(fork()==0){
	sleep(5);
	cout<<"Child process with id :"<<getpid()<<" with parent id : "<<getppid()<<endl;
	exit(0);
}}

wait(NULL);

return 0;
}

