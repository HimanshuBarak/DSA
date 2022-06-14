<h2>Coin Change(Fewest Coins)</h2>
<h3>Medium</h3><hr>
<div><p>
  You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 
</p>


[Problem Link](https://leetcode.com/problems/coin-change/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> coins = [1,2,5], amount = 11
<strong>Output:</strong> 3
<strong>Explanation:</strong> 11 = 5 + 5 + 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> coins = [2], amount = 3
     
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Treat it like unbounded knapsack and consider val of each coin as 1 add that when you select a coin
  2. The intialisatiion is the only tricky part which needs figuring out and once u dry run you can figure it out
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int coinChange(vector<int>& wt, int w) {
        
       
        int n=wt.size(); 
        int dp[12+1][10000+1];
        memset(dp,-1,sizeof(dp));
               
        //this assignment is the whole crux of this question
       for(int i=0;i<=w;i++)
           dp[0][i]=INT_MAX-1;
        for(int i=0;i<=n;i++)
           dp[i][0]=0;
        
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=w;j++)
           {
               if(wt[i-1]<=j)
                   dp[i][j] = min(1+dp[i][j-wt[i-1]],0+dp[i-1][j]);
               else
                   dp[i][j]=dp[i-1][j];
           }
       }/*
        for(int i=0;i<=n;i++)
        {
           for(int j=0;j<=w;j++)
           {
                cout<<dp[i][j];
           } cout<<endl;
        } */  
        return dp[n][w]>=INT_MAX-1?-1:dp[n][w];
    }
};
  ```
</div>
