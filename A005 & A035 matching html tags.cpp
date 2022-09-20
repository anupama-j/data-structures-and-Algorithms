#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

int n;

std::stack<int> s;
void checkTag(char ele[], char arr[], int size){
int i = 0, k = 0, tagno;

while(i<size){
    if (ele[i] == '<'){
      while(ele[i] != '>'){
        arr[k] = ele[i];
        i++;
        k++;
      }
      if(ele[i] == '>'){
        arr[k] = ele[i];
        k++;
      }
    }
    i++;
  }
}
void error(int n){
	if(n==49){
		cout<<"html not closed";
	}else if(n==50){
		cout<<"head not closed";
	}else if(n==51){
		cout<<"body not closed";
	}
}

  void TagPush(char arr[], int size){
    stack<char> s;
    string ch = "";
    int i = 0, weight;
   
    while(i<size){
    int j=0;
    if (arr[i] == '<'){
      i += 1;
      while(arr[i] != '>'){
        ch += arr[i];
        i++;
      }
      cout<<endl<<ch<<" ";
     
     
      if(ch=="html"){
      s.push('1');
  	  }
      else if(ch=="head"){
      s.push('2');
  	  }
  	  else if(ch=="body"){
      s.push('3');
  	  }
      else if(ch=="/body"){
      if(s.top()=='3'){
      	s.pop();
	  }else{
	  	n = s.top();
	  	error(n);
	  	return;
	  }
  	  }
      else if(ch=="/head"){
      if(s.top()=='2'){
      	s.pop();
	  }else{
	  	n = s.top();
	  	error(n);
	  }
  	  }
      else if(ch=="/html"){
      if(s.top()=='1'){
      	s.pop();
	  }else{
	  	n = s.top();
	  	error(n);
	  	return;
	  }
  	  }
     
    }
    ch = "";
    i++;
  }
 
  if(s.size()%2!=0){
  cout<<"tags miss";
  }
  else{
  cout<<"\n\n\tNo Error";
    }
  
}
int main(){
char elements[] = "<html><head>HelloWorld</head><body></html>";   //input
int size = strlen(elements);
char TagsArr[size];

checkTag(elements,TagsArr,size);
cout<<"\nElements :: "<<elements;
cout<<"\nTags :: "<<TagsArr;

size = strlen(TagsArr);
TagPush(TagsArr, size);

return 0;
}
