<h2>House Robber</h2>
<h3>Medium</h3><hr>
<div><p>
  ou are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 
</p>


[Problem Link](https://leetcode.com/problems/house-robber/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
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
    class Solution {
public:
    int solve(vector<int> &arr,int n,int dp[])
    {
        
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] =max(solve(arr,n-1,dp),arr[n]+solve(arr,n-2,dp));
    }
    int rob(vector<int>& arr) {
        
       int dp[arr.size()];
        memset(dp,-1,sizeof(dp));
      return   solve(arr,arr.size()-1,dp);
    }
};
  
  //Part two All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
  class Solution {
public:
     
     int solve(vector<int> &arr,int n,int dp[],int start)
     {
        if(n<start)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
 
        return dp[n] =max(arr[n]+solve(arr,n-2,dp,start),solve(arr,n-1,dp,start));
        
     }
    int rob(vector<int>& arr) {
       
      int dp[arr.size()];
      int  n=arr.size()-1;
        if(n==0)
            return arr[0];
      memset(dp,-1,sizeof(dp));
        int a = solve(arr,n,dp,1);
         memset(dp,-1,sizeof(dp));
        int b =solve(arr,n-1,dp,0);
      return   max(a,b);
    }
    
};
  ```
</div>
