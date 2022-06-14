<h2>Rod cutting Problem</h2>
<h3>Medium /Easy</h3><hr>
<div><p>
  Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N.
  Determine the maximum value obtainable by cutting up the rod and selling the pieces.

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/rod-cutting0840/1)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}

<strong>Output:</strong> 22
<strong>Explanation:</strong> The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
     
<strong>Output:</strong> 24
<strong>Explanation:</strong> The maximum obtainable value is 
24 by cutting the rod into 8 pieces 
of length 1, i.e, 8*3=24. 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Exactly same as unbounded knapscak
  2. Just make a array of length 1 to n
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int len[n];
        for(int i=0;i<n;i++)
        {
            len[i]=i+1;
        }
        int dp[n+1][n+1];
        memset(dp,-1,sizeof(dp));
        //intialization
        for(int i=0;i<=n;i++)
          dp[0][i]=0;
        
        for(int i=0;i<=n;i++)
          dp[i][0]=0;
          
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
          {
              if(len[i-1]<=j)
                dp[i][j]= max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
             else
              dp[i][j]=dp[i-1][j];
          }
        return dp[n][n];  
    }
};
  ```
</div>
