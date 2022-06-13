<h2>Minimum Subset Sum Differnce</h2>
<h3>Medium</h3><hr>
<div><p>
  Given an integer array A containing N integers.

You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.

Find and return this minimum possible absolute difference.

NOTE:

Subsets can contain elements from A in any order (not necessary to be contiguous).
Each element of A should belong to any one subset S1 or S2, not both.
It may be possible that one subset remains empty.

 
</p>


[Problem Link](https://www.interviewbit.com/problems/minimum-difference-subsets/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> A = [1, 6, 11, 5]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Subset1 = {1, 5, 6}, sum of Subset1 = 12
  Subset2 = {11}, sum of Subset2 = 11
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
  1. Basically the last row of the dp array gives all possible of subset sum that are possible 
  2. Choose the one that gives the minimum differnce
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  int Solution::solve(vector<int> &arr) {

       int n=arr.size();
       int sum=0;
       for(int i=0;i<n;i++)
          sum+=arr[i];

       
       int dp[n+1][sum+1];
       memset(dp,0,sizeof(dp));
       
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=sum;j++)
           {
              if(i==0) dp[i][j]=0;
              if(j==0) dp[i][j]=1;
           }
       }
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=sum;j++)
           {
              if(arr[i-1]<=j)
               dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
               //basically transalates to not include(take the previous one) or include
               // j- arr[i-1] checks if curr element - sum is a valid element
              else
               dp[i][j] = dp[i-1][j];
           }
       }       
       int res =INT_MAX;
       //we know the last row of 2d array gives the possile values of subset sums
       //we check for sum/2 half length and whichever gives min difference we return it
       for(int i=0;i<=sum/2;i++)
       {
           if(dp[n][i]==1)
           {
             res = min(res, sum-i*2);
           }
             
       }
       return res;
}

  ```
</div>
