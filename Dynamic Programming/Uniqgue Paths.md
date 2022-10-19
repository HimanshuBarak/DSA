<h2>Unique Paths</h2>
<h3>Medium</h3><hr>
<div><p>
  You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 
</p>


[Problem Link](https://leetcode.com/problems/unique-paths-ii/)

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
  // Recursive Solution => Time = O(N*M) Space=> O(N+M) (recursive stack + O(N*M)
  class Solution {
public:
    long long mod = 2000000000;
    int f(int i,int j,vector<vector<int>> &mt,vector<vector<int>> &dp)
   {
    if(i==0 &&j==0)
        return 1;
    if(i<0 || j<0 || mt[i][j]==1)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    return dp[i][j] = (f(i-1,j,mt,dp)%mod+f(i,j-1,mt,dp)%mod)%mod;
   }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
         vector<vector<int>> dp(n,vector<int>(m,-1));
    if(mat[n-1][m-1]==1 ||mat[0][0]==1)
        return 0;
    return f(n-1,m-1,mat,dp);
    }
};
  //Tabulation 
  
class Solution {
public:
    long long mod = 2e9;
    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
    
    int n=mat.size(), m=mat[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
        
    if(mat[n-1][m-1]==1 ||mat[0][0]==1)
        return 0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   
            if(i==0 && j==0)
             dp[i][j]=1;
            else if(mat[i][j]==1)
                dp[i][j]=0;
            else if(i==0)
                dp[i][j]=dp[i][j-1];
            else if(j==0)
                dp[i][j]=dp[i-1][j];
            else 
                dp[i][j] = (dp[i][j-1]%mod+dp[i-1][j]%mod)%mod;
        }
    }
    return dp[n-1][m-1];
    }
};
  
  //Space Optimisation
  
class Solution {
public:
    long long mod = 2e9;
    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
    
    int n=mat.size(), m=mat[0].size();
    vector<int> prev(m,0);
        
    if(mat[n-1][m-1]==1 ||mat[0][0]==1)
        return 0;
    
    for(int i=0;i<n;i++)
    {   vector<int> temp(m,-1);
        for(int j=0;j<m;j++)
        {   
            if(i==0 && j==0)
             temp[j]=1;
            else if(mat[i][j]==1)
                temp[j]=0;
            else if(i==0)
                temp[j]=temp[j-1];
            else if(j==0)
                temp[j]=prev[j];
            else 
                temp[j] = (temp[j-1]%mod+prev[j]%mod)%mod;
        }
     prev=temp;
    }
    return prev[m-1];
    }
};
                           //  Space //O(M)
  
  ```
</div>
