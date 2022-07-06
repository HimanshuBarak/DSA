<h2>Kth smallest element in sorted array</h2>
<h3>Medium</h3><hr>
<div><p>
  Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.

 
</p>


[Problem Link]()

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
<strong>Output:</strong> 6
<strong>Explanation:</strong> The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
     
<strong>Output:</strong> 256
<strong>Explanation:</strong> Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
``` c++
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
      //if  a is not the smaller array we switch
        if(n>m)
        {
            return kthElement(arr2,arr1,m,n,k);
        }
       
        //the maximum and minimum no. of elements  we can take from the smaller array
        int low =max(0,k-m),high=min(k,n);
        while(low <= high) {
            //the maximum and minimum no. of elements  we can take from the smaller array
            int cut1 = (low + high)/2; 
            int cut2 = k - cut1; 
             //define the leftmost and rightmost element to the partitions
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
            int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
             //if left to the partion is all less than right to the partition
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 1;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends
```
