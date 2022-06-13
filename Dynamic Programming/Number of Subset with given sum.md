<h2>Number of Subset With given Sum</h2>
<h3>Medium</h3><hr>
<div><p>
  
You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number “tar”.
 
</p>


[Problem Link](https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 4 and tar = 3 and the array elements are [1, 2, 2, 3]
<strong>Output:</strong> number of possible ways are:
{1, 2}
{3}
{1, 2}
Hence the output will be 3.
<strong>Explanation:</strong> 
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
  1. Basically at each step we are adding all the values that can give sum as target ,very similar to subset sum here instead of true and false
  2. we return 1 and 0 and add these on each call
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
      //recursion
  int dp[101][1001];

int  helper(vector<int>arr, int sum,int n)
  {
       if(sum==0)
        return 1;
       if(n==0)
        return 0;
      
      if(dp[n][sum]!=-1)
        return dp[n][sum];
      if(arr[n-1]<=sum)
       {
         return dp[n][sum]= (helper(arr,sum,n-1)+helper(arr,sum-arr[n-1],n-1));
            
       }
       else
        return dp[n][sum]=helper(arr,sum,n-1);
  }
    


int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    for(int i=0;i<=num.size();i++)
        for(int j=0;j<=tar;j++)\
            dp[i][j]=-1;
    return helper(num,tar,num.size());
  
} 
  
  
  // Bottom UP Approach
  
  int n=arr.size();
    int dp[101][1001];
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
             dp[i][j] = dp[i-1][j]+ dp[i-1][j-arr[i-1]];
            else
             dp[i][j] = dp[i-1][j];
         }
     }       
    return dp[n][sum];
  ```
</div>
