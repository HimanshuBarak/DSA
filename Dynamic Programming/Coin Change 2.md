<h2>Coin Change</h2>
<h3>Medium</h3><hr>
<div><p>
  You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 
</p>


[Problem Link](https://leetcode.com/problems/coin-change-2/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> amount = 5, coins = [1,2,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
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
  1. Similar to subset sum just add no. of ways
  2. Only difference you can select a coin multiple times
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    /* This is exactly same as subset sum count except the part where we can select a coin as many times as we want
      thing to notice is we can choose not to select any of the coins that is also valid way
    */
    int change(int amt, vector<int>& coins) {
         int n=coins.size();
        
        int dp[n+1][amt+1];
        
        for(int i=0;i<=amt;i++)
           dp[0][i] = 0;
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
       
            
            
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amt;j++)
            {
                if(coins[i-1]<=j)
                    dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
       
            return dp[n][amt];
    }
};
  ```
</div>
