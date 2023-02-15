#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main(){
	int id;
	id= fork (); //create a process
	if(id<0){   // Error creating process
	cout<<"Can't create a file (Error)"<<endl;  
	exit(-1);
	}
	if (id!=0){
		cout<<"Parent Process with id :"<<getpid()<<"  and Parent id : "<<getppid()<<endl;
	}else{
		cout<<"Chlid  Process with id :"<<getpid()<<"  and Parent id : "<<getppid()<<endl;
	}

return  0;
}

