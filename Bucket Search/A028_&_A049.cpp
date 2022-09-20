	/*
						       ******* Bucket Search *******
		Sem 3 Data Structure MiniProject Narsee Monjee College of Commerce and Economics
		Made By Veer Nagda A028 and Farhan Surani A049
		Under guidance of Ma'am Anupama Jawale, B.Sc. I.T.
																							*/

#include <iostream>
#include <bits/stdc++.h>
  
using namespace std;  
int sorted[100];
int getMax(int a[], int n) // function to get maximum element from the given array  
{  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return (max+10)/10;  
}  
void bucket(int a[], int n) // function to implement bucket sort  
{  
	int max = getMax(a, n); //max is the maximum element of array  
	int bucket[max][n], i,j,k,l,m=0;
	for(i=0;i<max;i++){
		j=0;
		for(k=0;k<10;k++){
			if(i*10<a[k] && (i+1)*10>a[k]){
				bucket[i][j]=a[k];
				j++;
				if(j>1)
					for (l = 0; l < j-1; l++)
	            		if (bucket[i][l] > bucket[i][l + 1])
	               			swap(bucket[i][l], bucket[i][l + 1]);
			}
		}
		for(l=0;l<j;l++){
			sorted[m]=bucket[i][l];
			cout << endl <<"sorted " <<m <<": " <<sorted[m];
			m++;
		}
		
        
	}
}  
void printArr(int a[], int n) // function to print array elements  
{  
  for (int i = 0; i < n; ++i)  
    cout<<a[i]<<" ";  
}  
int main()  
{  
  int a[] = {31,32,33,34, 42, 74, 57, 98, 99, 84};  
  int n = sizeof(a) / sizeof(int); // n is the size of array  
  cout<<"Before sorting array elements are - \n";  
  printArr(a, n);  
  bucket(a, n);  
  cout<<"\nAfter sorting array elements are - \n";  
  printArr(sorted, n); 
  cout << endl;
  system("pause");
}  
