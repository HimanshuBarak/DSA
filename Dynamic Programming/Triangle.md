<h2>Triangle</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 
</p>


[Problem Link]()

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>
<strong>Output:</strong> 
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
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    
int f(int i,int j,int n,vector<vector<int>> &t,vector<vector<int>> &dp)
{
    if(i==n-1)
        return t[i][j];
    if(j>i)
        return INT_MAX;
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int down = f(i+1,j,n,t,dp);
    int diag = f(i+1,j+1,n,t,dp);
    
    return dp[i][j] = t[i][j]+min(down,diag);
}
    
    
int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
    /*
        vector<vector<int>> dp(n,vector<int>(1,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i].push_back(-1);
            }
        }
         dp[0][0]=t[0][0];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int top=INT_MAX,diag=INT_MAX;
                if(j>0)
                    diag=dp[i-1][j-1];
                if(j<i)
                    top=dp[i-1][j];
                dp[i][j] = t[i][j]+min(top,diag);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
          ans=min(ans,dp[n-1][i]);  
        }
     */
    vector<int> prev(n,-1);
    prev[0]=t[0][0];
    for(int i=1;i<n;i++)
        {   vector<int> temp(n,0);
            for(int j=0;j<=i;j++)
            {
                int top=INT_MAX,diag=INT_MAX;
                if(j>0)
                    diag=prev[j-1];
                if(j<i)
                    top=prev[j];
                temp[j] = t[i][j]+min(top,diag);
            }
         prev=temp;
        }
       int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
          ans=min(ans,prev[i]);  
        }
        return ans;
    }
};
  ```
</div>
