#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <ostream>
#include <istream>

using namespace std;
	
	std::queue<std::string> q; //operating Q
	std::queue<std::string> Q; //Read Q
	std::queue<std::string> p; //Pre-built Q
	
void operQ();
void preQ();
void reverseQueue(queue<std::string>& q);
void qback();
void qfront();
void allmssg();
void rallmssg();
void inp();
void mssg();

int main ()
{
	int n;
	cout<<"------------->PENDING MESSAGES IN QUEUE<----------";
  	
	operQ();
  	preQ();
	
	do{
	
  	cout<<"\n\n1. See the Number of Pending Messages\n";
  	cout<<"2. Read the Latest(Recent) Message\n";
  	cout<<"3. Read the Oldest Message\n";
  	cout<<"4. Read all the Messages together\n";
  	cout<<"5. Display all Read Messages\n";
  	cout<<"6. Add a Message\n";
  	cout<<"7. Display all the Pre-Built Messages\n";
  	cout<<"8. Exit\n";
  	cout<<"Enter your choice: ";
  	std::cin>>n;
  	
	switch(n){
  	case 1:
  		cout<<"\n\nNumber of Pending(Unread) Meassages: "<<q.size();
  		break;
  	
  	case 2:
  		qback();
  		break;
  	
  	case 3:
  		qfront();
  		break;
  	
  	case 4:
  		allmssg();
  		break;	
  
  	case 5:
  		rallmssg();
  		break;
  		
  	case 6:
  		inp();
  		
	  	break;
	
	case 7:
  		mssg();
  		break;	
	   	
  	default:
  		cout<<"Wrong Choice";
  		break;
  		}
	}while(n!=8);
  return 0;
}

	
void operQ(){
	q.push ("Go for it");
  	q.push ("Got your back");
  	q.push ("How are you?");
 	q.push("Nothing is impossible");
 	q.push("Do the best you can");
}
void preQ(){
	p.push ("Go for it");
  	p.push ("Got your back");
  	p.push ("How are you?");
 	p.push("Nothing is impossible");
 	p.push("Do the best you can");
}

//case 2
void qback(){
	cout << "\nLatest(Recent) Message: " << q.back();
  		Q.push(q.back());
		reverseQueue(q);
  		q.pop();
  		reverseQueue(q);
}
void reverseQueue(queue<std::string>& q)
{
    stack<std::string> Stack;
    while (!q.empty()) {
        Stack.push(q.front());
        q.pop();
    }
    while (!Stack.empty()) {
        q.push(Stack.top());
        Stack.pop();
    }
}

//case 3
void qfront(){
	cout << "\nLatest(Recent) Message: " << q.front();
  		Q.push(q.front());
  		q.pop();
}

//case 4
void allmssg(){
	cout<<"\nDisplaying all the Pending Messages:\n";
	while (!q.empty ())
    	{
      		std::cout << q.front () << std::endl;
      		Q.push(q.front());
      		q.pop();
    	}
  			std::cout<< std::endl;
}

//case 5
void rallmssg(){
	cout<<"\nDisplaying all the Read Messages:\n";
  		while(!Q.empty())
    	{
      		std::cout << Q.front () << std::endl;
      		Q.pop();
    	}
  			std::cout<< std::endl;
  	}

//case 6
void inp(){
	
	std::string input;
  	std::cout << "Please input a Message: " << std::endl;
  	std::cin.ignore();
 	std::getline(cin,input);
 	q.push(input);
 	cout<<"\nMessage Send Succesfully.\n";
 }

//case 7
void mssg(){
	cout<<"\nDisplaying all the Pre-Built Messages:\n";
	while (!p.empty ())
    	{
      		std::cout << p.front () << std::endl;
      		
      		p.pop();
    	}
  			std::cout<< std::endl;
  		preQ();
}
