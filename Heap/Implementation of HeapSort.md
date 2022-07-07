

```c++



//implementing a max heap

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//insertion inside a heap

// start from the last index and keep swapping until parent is smaller than the current element
void insert(int A[],int n)
{
     int temp =A[n];
     int i=n;
     
     while(i>1 && temp >A[i/2])
     {
         A[i] =A[i/2];
         i=i/2; 
     }
     A[i]=temp;
}

// function to delete from a heap (we know the max value (index 0) is always deleted from a heap)
//thats where deletion takes place
void deleteVal(int A[],int n)
{
    int x=A[1]; //replacing first element with the last element
    int i=1;
   
    A[1]=A[n];
     A[n]=x;
    int j=2*i;
    
    while(j<n-1)
    {  //pointing j to the larger children
       if(A[j+1]>A[j])
         j=j+1;
         
       if(A[i]<A[j])
       {
           swap(A[i],A[j]);
           i=j;
           j=2*j;
       }else
          break; //if parent is greater no need of adjustments
       
    }    
    
}

int main()
{
    // the first value 3 in this case forms a max heap in itself(as its a single value)
    int  arr[] = {0,3,4,5,7,9};
    
    for(int i=2;i<6;i++)
       insert(arr,i); //sending the last index the index whose number is to be inserted 
    
    
    for(int i=5;i>1;i--){
        deleteVal(arr,i);  //we have to send the last index of the heap
         
    }
     for(int i=1;i<6;i++)
         cout<<arr[i]<<" ";
       cout<<endl;     
   
     
    return 0;
}

```
