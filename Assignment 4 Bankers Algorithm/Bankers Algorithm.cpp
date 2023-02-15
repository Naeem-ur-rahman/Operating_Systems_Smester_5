#include<iostream>
#include <iomanip>
using namespace std;
class Process{
    int   total_resourses;
	int   total_prcesses;
	
	int   *max_resourses;
	int   *allocated;
	int   *available;
	
	bool  *running_processes;
	
	int   allocate_table[30][20];
	int   max_claim_process[30][20];
	
	
	void get_max_resoures(){
		cout<<"Enter the Total MAX resoures Instances"<<endl;
		for(int i=0;i<total_resourses;i++){
			cout<<"Enter R"<<i+1<<" : ";cin>>max_resourses[i];
		}
		cout<<endl;
	}
	void print_max_resourses(){
		cout<<"Total MAX resoures Instances Are : "<<endl;
		for(int i=0;i<total_resourses;i++){
			cout<<"R"<<i+1<<" : "<<setiosflags(ios::left)<<setw(10)<<max_resourses[i];
		}
		cout<<endl;
		line(70);
	}
	void line(int n){
		for(int a=1;a<=n;a++){
			cout <<"_";
		}
		cout<<endl;
	}
	void status_running_at_start(){
		for(int i=0 ;i<total_prcesses;i++){
			running_processes[i] = true;
		}
	}
	void get_allocate_table(){
		cout<<"Enter the allocation table of the Processes !"<<endl;
		for(int i=0;i<total_prcesses;i++){
			cout<<"Process "<<i+1<<endl;
			for(int j=0;j<total_resourses;j++){
				cout<<"R"<<j+1<<" Allocated : ";cin>>allocate_table[i][j];
			}
			cout<<endl;
		}
	}
	void print_allocate_table(){
		cout<<"Allocated Table "<<endl;
		line(70);
		cout<<setiosflags(ios::left)<<setw(12)<<"Process";
		for(int p=1;p<=total_resourses;p++){
			cout<<"R"<<setiosflags(ios::left)<<setw(12)<<p;
		}
		cout<<endl;
		line(70);
		for(int i=0;i<total_prcesses;i++){
			
			cout<<setiosflags(ios::left)<<setw(12)<<i+1;
			for(int j=0;j<total_resourses;j++){
				cout<<setiosflags(ios::left)<<setw(12)<<allocate_table[i][j];
			}
			cout<<endl;
		}
		line(70);
	}
	void get_max_claim_table(){
		cout<<"Enter the MAX Claim table of the Processes !"<<endl;
		for(int i=0;i<total_prcesses;i++){
			cout<<"Process "<<i+1<<endl;
			for(int j=0;j<total_resourses;j++){
				cout<<"R"<<j+1<<" MAX Claim : ";cin>>max_claim_process[i][j];
			}
			cout<<endl;
		}
	}
	void print_max_claim_table(){
		cout<<"MAX Claim Table "<<endl;
		line(70);
		cout<<setiosflags(ios::left)<<setw(12)<<"Process";
		for(int p=1;p<=total_resourses;p++){
			cout<<"R"<<setiosflags(ios::left)<<setw(12)<<p;
		}
		cout<<endl;
		line(70);
		for(int i=0;i<total_prcesses;i++){
			
			cout<<setiosflags(ios::left)<<setw(12)<<i+1;
			for(int j=0;j<total_resourses;j++){
				cout<<setiosflags(ios::left)<<setw(12)<<max_claim_process[i][j];
			}
			cout<<endl;
		}
		line(70);
	}
	
	void get_allocated_resourses(){
		for(int i=0;i<total_prcesses;i++){
			for(int j=0;j<total_resourses;j++){
				allocated[j] += allocate_table[i][j];
			}
		}
	}
	void print_allocated_resoures(){
		cout<<"Allocated Resourse are : "<<endl;
			for(int i=0;i<total_resourses;i++){
			cout<<"R"<<i+1<<" : "<<setiosflags(ios::left)<<setw(10)<<allocated[i];
		}
		cout<<endl;
		line(70);
	}
	void get_available_resourses(){
		for(int i=0;i<total_prcesses;i++){
			for(int j=0;j<total_resourses;j++){
				available[j] = max_resourses[j] - allocated[j];
			}
		}
	}
	void print_available_resoures(){
		cout<<"Available Resourse are : "<<endl;
			for(int i=0;i<total_resourses;i++){
			cout<<"R"<<i+1<<" : "<<setiosflags(ios::left)<<setw(10)<<available[i];
		}
		cout<<endl;
		line(70);
	}
	void set_array(int *value,int size){
		for(int i=0;i<size;i++){
			value[i]=0;
		}
	}
	void check_save(){
		int safe,exec,count=total_prcesses;
		while (count != 0){
          safe = 0;
          for (int i = 0; i < total_prcesses; i++){
               if (running_processes[i]){
                    exec = 1;
                    for (int j = 0; j < total_resourses; j++){
                         if (max_claim_process[i][j] - allocate_table[i][j] > available[j]){
                              exec = 0;
                              break;
                         }
                    }
                    if (exec){
                         
						 cout<<"Process "<< i + 1<<" is executing"<<endl;
                         running_processes[i] = false;
                         count--;
                         safe = 1;

                         for (int j = 0; j < total_resourses; j++){
                              
							  available[j] += allocate_table[i][j];
                         }
                         break;
                    }
               }
          }
          if (!safe) {
               
			   cout<<"The process is in unsafe state."<<endl;
               break;
          }
          else {
          	
               cout<<"Your process is in safe state"<<endl;
               cout<<"Available vector :";

               for (int i = 0; i < total_resourses; i++)
               {
                    cout<< available[i] <<"  ";
               }
               
               cout<<endl<<endl;
          }
     }
	}
	
	public :
	Process(int resourses,int processes){
		total_prcesses = processes;
		total_resourses = resourses;
		max_resourses = new int [total_resourses];
		allocated     = new int [total_resourses];
		available     = new int [total_resourses];
		set_array(allocated,total_resourses);
		set_array(available,total_resourses);
		
		get_max_resoures();
		
		running_processes = new bool[total_prcesses];
		status_running_at_start();
		
		get_allocate_table();
		get_max_claim_table();
		get_allocated_resourses();
		get_available_resourses();
		
		print_allocate_table();
		print_max_claim_table();
		print_max_resourses();
		print_allocated_resoures();
		print_available_resoures();
		check_save();	
		
	}
};

int main(){
	int processes,resourses;
	cout<<"Enter Number of Processes : ";cin>>processes;
	cout<<"Enter Number of Resourses : ";cin>>resourses;
	
	Process p = Process(resourses,processes);
	
	
	return 0;
}
