//BFS
//A019_45207210060_Parth Kakadia
#include<iostream>
#include<stdlib.h>
using namespace std;
struct queue{
    int size;
    int f;
    int r;
    int* arr;
};
//Empty 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
//Full
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
//Enequeue
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        cout<<"This Queue is full\n";
    }else{
        q->r++;
        q->arr[q->r] = val;
//        cout<<"\nEnqued element:"<<val;
    }
}
//Dequeue
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        cout<<"This Queue is empty\n";
    }else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
//main--------------------------------------------
main(){
	system("Color CE");
    struct queue q; 
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));   
	cout<<"BFS "<<endl;
	//Implementaion BFS
	int i, j;
	int n=7;
	cout<<"Enter your source node (0-6) : ";
	cin>>i;
	int visited[7]={0,0,0,0,0,0,0};
	//Graph-------------
	int a[7][7]={
		{0,1,1,1,0,0,0},
		{1,0,1,0,0,0,0},
		{1,1,0,1,1,0,0},
		{1,0,1,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
	};
	cout<<"Source: "<<i<<endl;
	cout<<"Visited:";
	visited[i] = 1;
	enqueue(&q, i);   //Enqueue i for exploration
	while(!isEmpty(&q)){
		int node = dequeue(&q);
		for(j=0; j<n; j++){
			if (a[node][j]==1  &&  visited[j]==0){      
				 cout<<" "<<j;
				 visited[j]=1;     //mark visited
				 enqueue(&q, j);  //Explore
			}
		}
	}
}
