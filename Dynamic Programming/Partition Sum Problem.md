<h2>Partition Sum Problem</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
</p>


[Problem Link](https://leetcode.com/problems/partition-equal-subset-sum/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,5,11,5]
<strong>Output:</strong> true
<strong>Explanation:</strong> The array can be partitioned as [1, 5, 5] and [11].
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
  1. Sum to be found is total_sum/2 
  2. Makes it exactly similar to subset sum problem
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
    class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        
        int sum =0,n=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1)  //if sum is odd can't be partioned into 2 valid subsets
            return false;
        sum=sum/2;
          //exactly same as subset problem from here
        int dp[n+1][sum+1];
        memset(dp,-1,sizeof(dp));
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
                if(nums[i]<=j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                else
                   dp[i][j] = dp[i-1][j];
            }
         }
        return dp[n][sum];
    }
};
  ```
</div>
