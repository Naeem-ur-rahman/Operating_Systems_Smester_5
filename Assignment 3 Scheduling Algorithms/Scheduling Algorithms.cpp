#include<iostream>
#include<string.h>
#include <conio.h>
#include <iomanip>
using namespace std;

struct Node{
	string process_name;
	int brust_time;
	int priority;
	Node *next;
	Node(string p_n,int b,int p){
		process_name = p_n;
		brust_time = b;
		priority=p;
		next =NULL;
	}
};

class Queue{
	Node *rear;
	Node *front;
	int size;
	
	void line(){
		for(int a=1;a<=100;a++){
			cout <<"_";
		}
		cout<<endl;
	}
	
	void line(int n){
		for(int a=1;a<=n;a++){
			cout <<"_";
		}
		cout<<endl;
	}
	
	string process_name_value(){
		string name;
		cout<< "Enter the Process Name  : ";getline(cin,name);
		return name;
	}
	
	int brust_time_value(){
		int v;
		cout<< "Enter the brust time    : ";cin>>v;cin.ignore();
		return v;
	}
	
	int priority_value(){
		int v;
		cout<< "Enter the priority      : ";cin>>v;cin.ignore();
		return v;
	}
	
	Node* swap(Node* ptr1, Node* ptr2){
			
    		struct Node* tmp = ptr2->next;
    		ptr2->next = ptr1;
    		ptr1->next = tmp;
    		return ptr2;
		}
	
	void bubbleSort_Brust_time(Node **head){
    		Node** h;
    		int i, j, swapped;
 
    		for (i = 0; i <= size; i++){
        		h = head;
        		swapped = 0;
 
        		for (j = 0; j < size - i - 1; j++){
 
            		Node* p1 = *h;
            		Node* p2 = p1->next;
 
            		if (p1->brust_time > p2->brust_time){

                			/* update the link after swapping */
                		*h = swap(p1, p2);
                		swapped = 1;
					}
 
            		h = &(*h)->next;
        		}
 
        		/* break if the loop ended without any swap */
        		if (swapped == 0)
            	break;
    		}		
		}
		
	void bubbleSort_Priority(Node **head){
    		Node** h;
    		int i, j, swapped;
 
    		for (i = 0; i <= size; i++){
        		h = head;
        		swapped = 0;
 
        		for (j = 0; j < size - i - 1; j++){
 
            		Node* p1 = *h;
            		Node* p2 = p1->next;
 
            		if (p1->priority > p2->priority){

                			/* update the link after swapping */
                		*h = swap(p1, p2);
                		swapped = 1;
					}
 
            		h = &(*h)->next;
        		}
 
        		/* break if the loop ended without any swap */
        		if (swapped == 0)
            	break;
    		}		
		}
	
	int orignal_brust_time(string name,Queue q){
		Node* temp = q.front;
		while(temp!=NULL){
		if(temp->process_name==name){
			return temp->brust_time;
		}	
		temp = temp->next;
		}
	}
		
	public :
		Queue(){
			front = NULL;
			rear = NULL;
			size = 0;
		}
		
		void enqueue(){
			if(front==NULL){
				front = new Node(process_name_value(),brust_time_value(),priority_value());
				size++;
				rear =  front;
			}
			else{
				Node *temp = new Node(process_name_value(),brust_time_value(),priority_value());
				size++;
				rear->next = temp;
				rear = temp;
			}
		}
		void dequeue(){
			if(front==NULL){
				cout<< "Under Flow Queue"<<endl;
			}
			else{
				//cout << "Dequeue Value is : "<<front->process_name<<endl;
				front = front->next;
				size--;
				if(front == NULL){
					rear = NULL;
				}
			}
		}
		void peek(){
			if (front==NULL){
				cout << "Empty Queue "<<endl;
			}
			else{
				cout<< "Peek Value is : "<<front->process_name<<endl;
			}
		}
		void display(){
			if(front==NULL){
				cout <<"Empty Queue"<<endl;
				return ;
			}
			cout << "Process Linked List Queue"<<endl;
			Node *temp = front;
				line();
				cout<<setiosflags(ios::left)<<setw(20)<<"Process's Name"
					<<setiosflags(ios::left)<<setw(15)<<"Brust Time"
					<<setiosflags(ios::left)<<setw(15)<<"Priority"<<endl; 
				line();
				
			while(temp!=NULL){
			cout <<setiosflags(ios::left)<<setw(20)<<temp->process_name
				 <<setiosflags(ios::left)<<setw(15)<<temp->brust_time
				 <<setiosflags(ios::left)<<setw(15)<<temp->priority<<endl;
				temp = temp->next;
			}
			line();
		}
		
		void copy_linkded_list(Queue q){
		Node* tempf = q.front;
		while(tempf!=NULL){
		
		if(front==NULL){
				front = new Node(tempf->process_name,tempf->brust_time,tempf->priority);
				size++;
				rear =  front;
			}
			else{
				Node *temp = new Node(tempf->process_name,tempf->brust_time,tempf->priority);
				size++;
				rear->next = temp;
				rear = temp;
			}
			tempf= tempf->next;
		}
	}
	
	
		float SJF(){
			if(front==NULL){
				cout <<"Empty Queue"<<endl;
				return 0 ;
			}
			bubbleSort_Brust_time(&front);
			int t = 0,newt=0;
			int avg_wait_time=0,no_of_process=0;
			Node *temp = front;
			cout<<endl;
			cout<<"------SJF Scheduling Chart-----"<<endl<<endl;
			line();
			while(temp!=NULL){
				avg_wait_time+=t;
				newt += temp->brust_time;
				cout <<"|"<<t<<","<<setiosflags(ios::left)<<setw(temp->brust_time/2)<<""
				                  <<setiosflags(ios::left)<<setw(temp->brust_time)<<temp->process_name
					 <<","<<newt<<"|";
			    t=newt;
				temp = temp->next;
				no_of_process++;
				
			}
			cout<<endl;
			line(newt+70);
			cout<<endl;
			cout<<"Avarage Wait Time is : "<<(float)avg_wait_time/no_of_process<<endl<<endl;
			return (float)avg_wait_time/no_of_process;
		}
		float Priority(){
			if(front==NULL){
				cout <<"Empty Queue"<<endl;
				return 0 ;
			}
			bubbleSort_Priority(&front);
			int t = 0,newt=0;
			int avg_wait_time=0,no_of_process=0;
			Node *temp = front;
			cout<<endl;
			cout<<"------Priority Scheduling Chart-----"<<endl<<endl;
			line();
			while(temp!=NULL || size==0){
				avg_wait_time+=t;
				newt += temp->brust_time;
				cout <<"|"<<t<<","<<setiosflags(ios::left)<<setw(temp->brust_time/2)<<""
				                  <<setiosflags(ios::left)<<setw(temp->brust_time)<<temp->process_name
					 <<","<<newt<<"|";
			    t=newt;
				temp = temp->next;
				no_of_process++;
				
			}
			cout<<endl;
			line(newt+70);
			cout<<endl;
			cout<<"Avarage Wait Time is : "<<(float)avg_wait_time/no_of_process<<endl<<endl;
			return (float) avg_wait_time/no_of_process;
		}
		float RR(int quantum,Queue q){
			if(front==NULL){
				cout <<"Empty Queue"<<endl;
				return 0;
			}
			int t = 0,newt=0,no_process=size;
			int avg_wait_time=0;
			
			cout<<endl;
			cout<<"------Round Robin Scheduling Chart-----"<<endl<<endl;
			line();
			while(front!=NULL){
				
				
				if(front->brust_time<=quantum){
					 newt += front->brust_time;
					 
					 cout <<"|"<<t<<","<<setiosflags(ios::left)<<setw(quantum/2)<<""
				                  <<setiosflags(ios::left)<<setw(quantum)<<front->process_name
					 <<","<<newt<<"|";
					 
					 avg_wait_time += newt - orignal_brust_time(front->process_name,q);
					 t=newt;
					 dequeue();
					 
				}else{
					newt += quantum;
						cout <<"|"<<t<<","<<setiosflags(ios::left)<<setw(quantum/2)<<""
				                  <<setiosflags(ios::left)<<setw(quantum)<<front->process_name
					 <<","<<newt<<"|";
					 t=newt;
					 string name = front->process_name;
					 int b_t = front->brust_time-quantum;
					 int p = front->priority;
					 
					 dequeue();
					 
					 if(front==NULL){
						front = new Node(name,b_t,p);
						size++;
						rear =  front;
					}
					else{
						Node *temp = new Node(name,b_t,p);
						size++;
						rear->next = temp;
						rear = temp;
					}
				}
				
			
			}
			cout<<endl;
			line(newt+70);
			cout<<endl;
			cout<<"Avarage Wait Time is : "<<(float)avg_wait_time/no_process<<endl<<endl;
			return (float) avg_wait_time/no_process;
			
		}
		float RR_wait(int quantum,Queue q){
			if(front==NULL){
				cout <<"Empty Queue"<<endl;
				return 0;
			}
			int t = 0,newt=0,no_process=size;
			int avg_wait_time=0;
			
			cout<<endl;
			cout<<"------Round Robin Scheduling Chart-----"<<endl<<endl;
			line();
			while(front!=NULL){
				
				
				if(front->brust_time<=quantum){
					 newt += front->brust_time;
					 
//					 cout <<"|"<<t<<","<<setiosflags(ios::left)<<setw(quantum/2)<<""
//				                  <<setiosflags(ios::left)<<setw(quantum)<<front->process_name
//					 <<","<<newt<<"|";
					 
					 avg_wait_time += newt - orignal_brust_time(front->process_name,q);
					 cout<<front->process_name<<"  wait time :  "<<newt-orignal_brust_time(front->process_name,q)<<endl;
					 
					 t=newt;
					 dequeue();
					 
				}else{
					newt += quantum;
//						cout <<"|"<<t<<","<<setiosflags(ios::left)<<setw(quantum/2)<<""
//				                  <<setiosflags(ios::left)<<setw(quantum)<<front->process_name
//					 <<","<<newt<<"|";
					 t=newt;
					 string name = front->process_name;
					 int b_t = front->brust_time-quantum;
					 int p = front->priority;
					 
					 dequeue();
					 
					 if(front==NULL){
						front = new Node(name,b_t,p);
						size++;
						rear =  front;
					}
					else{
						Node *temp = new Node(name,b_t,p);
						size++;
						rear->next = temp;
						rear = temp;
					}
				}
				
			
			}
			cout<<endl;
			line(newt+70);
			cout<<endl;
			cout<<"Avarage Wait Time is : "<<(float)avg_wait_time/no_process<<endl<<endl;
			return (float) avg_wait_time/no_process;
		}
};

int main(){
	int n,quantum;
	cout<<"Enter the no of Programs  : ";cin>>n;
	cin.ignore();
	cout<<"Enter the time Quantum    : ";cin>>quantum;
	cin.ignore();
	
	Queue q ;
	for (int i=1;i<=n;i++){
		cout<<"Enter the "<<i<<" Process Data ! "<<endl;
		q.enqueue();
		cout<<endl;
	}
	cout<<endl;
	q.display();
	
	Queue q1 , q2, q3,q4;
	q1.copy_linkded_list(q);
	q2.copy_linkded_list(q);
	q3.copy_linkded_list(q);
	q4.copy_linkded_list(q);
	float SJF = q1.SJF();
	float Pri = q2.Priority();
	float RR  = q3.RR(quantum,q);
	q4.RR_wait(quantum,q);
	cout<<endl;
	if(SJF<Pri){
		if(SJF<RR){
			cout<<"Shortest Job First (SJF) is the best algorithm for these Process Scheduling! "<<endl;
		}else{
			cout<<"Round Robin (RR) is the best algorithm for these Process Scheduling! "<<endl;
		}
	}else{
		if(Pri<RR){
			cout<<"Priority Scheduling is the best algorithm for these Process Scheduling! "<<endl;
		}else{
			cout<<"Round Robin (RR) is the best algorithm for these Process Scheduling! "<<endl;
		}
		
	}
	
	
	return 0;
}
