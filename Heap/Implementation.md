

```c++

//implementing a max heap

#include <iostream>

using namespace std;

//insertion inside a heap

// start from the last index and keep swapping until parent is smaller than the current element
void insert(int A[],int n)
{
     int temp =A[n];
     int i=n;
     
     while(i>1 && A[i/2]<A[i])
     {
         A[i] =A[i/2];
         i=i/2; 
     }
     A[i]=temp;
}

// function to delete from a heap (we know the max value (index 0) is always deleted from a heap)
//thats where deletion takes place
void delete(int A[],int n)
{
    int x=A[1]; //replacing first element with the last element
    A[i]
    int i=1
    while(j<n-1 && )
}

int main()
{
    // the first value 3 in this case forms a max heap in itself(as its a single value)
    int  arr[] = {0,3,4,5,7,9};
    
    for(int i=2;i<6;i++)
       insert(arr,i); //sending the last index the index whose number is to be inserted 
    for(int i=1;i<6;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}

```
