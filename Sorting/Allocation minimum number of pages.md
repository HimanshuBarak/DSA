<h2>Allocate minimum number of pages </h2>
<h3>Medium</h3><hr>
<div><p>
  You are given N number of books. Every ith book has Ai number of pages. The books are arranged in ascending order.

You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 4
A[] = {12,34,67,90}
M = 2
<strong>Output:</strong> 113 
<strong>Explanation:</strong> Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  // { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //see it like this we need to find the maximum number of pages that a student
        //can read ,and using this value we find the no. of students required 
        //with this max. no of pages once we find it we try to minimize this
        
        int sum=0;
        for(int i=0;i<n;i++)
          sum+=a[i];
          
        int low=0,high=sum;
        int max=0,res=a[0];
        while(low<=high)
        {
             max = low+ (high-low)/2;
            int cnt=0;
            sum=0;
            //if the max is less than a[i] than that value of max is invalid
            //as its too low and will the book unallocated hence max should be increased
            for(int i=0;i<n;i++)
              {
                  sum+=a[i];
                  if(sum>max)
                    sum=a[i],cnt++;
                  if(a[i]>max) //this allocation is too low max needs to be increased 
                  {
                      cnt=INT_MAX-1 ;break;
                  }
                    
              }
            if(sum>0) cnt++;
           
          // cout<<"count :"<<cnt<<" "<<low<<"  "<<max<<" "<<high<<endl;
            if(cnt>m)  //the max page limit set per person is too low ,increase it get m==cnt
             low=max+1;
            else //the page limit is too high
             high=max-1;
            
        }
        
        return low; //low will be returned beacuse in end it will be at boundry
         // e.g at 112 and as there cnt>m low will cross to other sided hence it be 113
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
  ```
</div>
