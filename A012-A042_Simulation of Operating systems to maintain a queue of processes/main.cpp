//A012 A042
//Rutu Ghevariya
// Heet Shah


#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 50;
int Queue_Size = 0;

struct process{
    string process;
    int priority;
}queue[MAX],temp_process1,temp_process2; 


int isEmpty(){
    if (Queue_Size)   
    {
        return 0;
    }
    return 1;
}

int isFull(){
    if (Queue_Size == MAX)
    {
        return 1;
    }
    return 0;
}

void prioriatize(){
    for (int i = 0; i < Queue_Size-1; i++)
    {
        for (int j = 0; j < Queue_Size-1-i; j++)
        {
            if (queue[j].priority < queue[j+1].priority)
            {
                temp_process2 = queue[j];
                queue[j] = queue[j+1];
                queue[j+1] = temp_process2;
            }
        }
    }
}

void display(){
    if(isEmpty())
    {
        cout<<"\n\nQueue is Empty\n";
    }
    else
    {
        cout<<"\n\nProcesses in the Queue Along With its Priorities\n";
        for (int i = Queue_Size-1; i >= 0; i--)
        {
            cout<<queue[i].process<<"(Priority:"<<queue[i].priority<<") --> ";
        }
        cout<<"Execution\n";
    }
}

void convert_to_uppercase(string& my_string){
    transform(my_string.begin(),my_string.end(),my_string.begin(),::toupper);
}

void enqueue(string process,int priority){
    if (isFull())
    {
        cout<<"\n\nCan't Insert New Process named "<<process<<" in the Queue \nQueue is Full\n\n";
    }
    string temp_string1,temp_string2;
    temp_string1 = process;
    convert_to_uppercase(temp_string1);
    for (int j = 0; j < Queue_Size; j++)
    {
        temp_string2 = queue[j].process;
        convert_to_uppercase(temp_string2);
        if (temp_string1 == temp_string2)
        {
            cout<<"\""<<queue[Queue_Size-1].process<<"\" name is already use for some other process in the queue.\nPlease take some other name\n\n"; 
            return;
        }
    }
    queue[Queue_Size].process = process;
    queue[Queue_Size].priority = priority;
    cout<<"\n\nSuccessfully inserted process "<<process<<" in the queue with priority "<<priority<<endl;
    Queue_Size++;
    for (int j = 0; j < Queue_Size; j++)
    {
        if (queue[Queue_Size-1].priority > queue[j].priority)
        {
            temp_process1 = queue[Queue_Size-1];
            queue[Queue_Size-1] = queue[j];
            queue[j] = temp_process1;
        }
    }
    display();
    // prioriatize(); 
}


struct process dequeue(){
    if(isEmpty()){
        cout<<"\n\nQueue is Empty\n\n";
    }
    else{
        temp_process1 = queue[0];
        int i;
        for (i = 0; i < Queue_Size; i++)
        {
            queue[i] = queue[i+1];
        }
        queue[i].process = "";
        queue[i].priority = 0; 
        Queue_Size--;
        // prioriatize();
        return temp_process1;
    }
}


void update_priority(string process,int newPriority){
    string temp_string1,temp_string2;
    temp_string1 = process;
    convert_to_uppercase(temp_string1);
    if(isEmpty()){
        cout<<"\n\nQueue is Empty\n\n";
    }
    else{
        for (int i = 0; i < Queue_Size; i++)
        {
            temp_string2 = queue[i].process;
            convert_to_uppercase(temp_string2);
            if (temp_string1 == temp_string2)
            {
                queue[i].priority = newPriority;
                prioriatize();
                return;
            }
        }
        cout<<"\n\nCan't Found Process Named "<<process<<"\nPlease Enter correct process name\n";
    }
    display();
}


int search_process(string process_name){
    if(isEmpty()){
        cout<<"\n\nQueue is Empty\n\n";
        return -1;
    }
    else{
        string temp_string1,temp_string2;
        temp_string1 = process_name;
        convert_to_uppercase(temp_string1);
        for (int i = 0; i < Queue_Size; i++)
        {
            temp_string2 = queue[i].process;
            convert_to_uppercase(temp_string2);
            if (temp_string1 == temp_string2)
            {
                return i+1;
            }
        }
        return 0;
    }
}




int main(){
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<"Simulation of Operating systems to maintain a queue of processes"<<endl;
	cout<<"----------------------------------------------------------------"<<endl;
    int choice;
    do
    {
    	cout<<endl;
    	cout<<"-----------------------------------------------";
        cout<<"\n1.ENTER NEW PROCESS IN THE QUEUE"<<endl;;
        cout<<"2.EXECUTE FIRST PROCESS WAITING IN THE QUEUE"<<endl;;
        cout<<"3.UPDATE PRIORITY OF ANY PROCESS"<<endl;;
        cout<<"4.SEARCH PROCESS IN THE QUEUE"<<endl;;
        cout<<"5.DISPLAY QUEUE"<<endl;
        cout<<"6.EXIT"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"\n\nEnter your choice : ";
        cin>>choice;
        if (choice == 1)
        {
            string process_name;
            cout<<"Enter the Process Name(In word) : ";
            cin>>process_name;
            int priority_value;
            cout<<"Enter the Process Priority(In Number) : ";
            cin>>priority_value;
            enqueue(process_name,priority_value);
        }
        else if (choice == 2)
        {
            temp_process1 = dequeue();
            cout<<"Executing Process "<<temp_process1.process<<"(Priority:"<<temp_process1.priority<<")\n"; 
            display();
        }
        else if (choice == 3)
        {
            string process_name;
            cout<<"Enter the Process Name : ";
            cin>>process_name;
            cout<<"Enter the New Priority(In Number) : ";
            int priority_value;
            cin>>priority_value;
            update_priority(process_name,priority_value);
            display();
        }
        else if(choice == 4){
            string process_name;
            cout<<"Enter the process name : ";
            cin>>process_name;
            int pos = search_process(process_name);
            if(pos == -1){
                //do nothing
            }
            else if (pos)
            {
                cout<<"\n\nProcess named \""<<process_name<<"\" found at position "<<pos<<endl<<endl;
            }
            else{
                cout<<"\n\nProcess named  \""<<process_name<<"\" can not found\n\n";
            }
        }
        else if (choice == 5)
        {
            display();
        }
        else if (choice < 0 || choice > 6)
        {
            cout<<"Please Enter valid choice\n\n";
        }
    } while (choice != 6);
    return 0;
}  
