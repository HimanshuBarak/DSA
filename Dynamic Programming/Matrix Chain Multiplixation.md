<h2>Matrix Chain Multiplication</h2>
<h3>Hard</h3><hr>
<div><p>
  
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 5
arr = {40, 20, 30, 10, 30}
<strong>Output:</strong> 
<strong>Explanation:</strong> There are 4 matrices of dimension 40x20, 20x30, 30x10, 10x30. Say the matrices are named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. The number of operations are -20*30*10 + 40*20*10 + 40*10*30 = 26000.
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
  1. 2 important things to note 
  2. A matrix can not be multiplied with itself and if muiltiple A*B*C*D => dimension of final matrix will be from A*D
  3. In MCM do it like these
  4. Find i and j
  5. Find base condition
  6. Find the range of k
  7. Calculate final ans from temporary ans
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution{
public:
    int dp[100+1][100+1];
    
    int mcm(int arr[],int i,int j)
    {
        if(i==j)  // only single matrix is left ,no other matrix left to multoply hence cost 0
          return 0;
          
        if(dp[i][j]!=-1)
          return dp[i][j];
          
        int ans =INT_MAX;  //we need minimum of this iteration not the overall minimum
        
        
        for(int k=i;k<=j-1;k++)
        {
            int temp = mcm(arr,i,k)+ mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            ans=min(temp,ans);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
      memset(dp,-1,sizeof(dp));  
      return  mcm(arr,1,n-1);
    }
};
  ```
</div>
