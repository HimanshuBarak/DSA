<h2>Maximize sum after K negations </h2>
<h3>Easy</h3><hr>
<div><p>
Given an array of integers of size N and a number K., Your must modify array arr[] exactly K number of times. Here modify array means in each operation you can replace
any array element either arr[i] by -arr[i] or -arr[i] by arr[i]. You need to perform this operation in such a way that after K operations, the sum of the array must be maximum.
</p>



<h3>  Your Task: </h3>
<p> 
You don't have to print anything, print ting is done by the driver code itself. You have to complete the function maximizeSum() which takes the array A[], its size N, and an integer K as inputs and returns the maximum possible sum.
</p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>
<strong>Output:</strong> 
<strong>Explanation:</strong> T
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>


  
  <h2> Solution </h2>
  
  ``` c++ 
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(a[i]>=0 ||k<=0)
             break;
            a[i]=-a[i];
            k--;
        }
        sort(a,a+n);
        if(k>=0 &&k%2==1)
        {
             a[0]=-a[0];
        }
        long long int sum=0;
        for(int i=0;i<n;i++)
         {
             sum+=a[i];
         }
         return sum; 
    }
};

  ```
</div>
