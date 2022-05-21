<h2>Unique Paths II</h2>
<h3>Medium</h3><hr>
<div><p>You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> obstacleGrid = [[0,1],[0,0]]
     
<strong>Output:</strong> 1
<strong>Explanation:</strong>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
   1. For each cell calculate the total possible ways to reach it (from left and top obv)
    2. This is pretty much it except for 0th row and column these neghbior wont be present so conditional statements for that
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public: 
    
   
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {        
       
        int m = grid.size();
        int n = grid[0].size();
         
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
            return 0;
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {     for(int j=0;j<n;j++)
            {   //incase its the boundary left and top
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else if(grid[i][j]==0)
                {
                    //adding the possible total paths of top cell and left cell    
                    dp[i][j] = (i>0?dp[i-1][j]:0) + (j>0?dp[i][j-1]:0);
                }else
                    dp[i][j]=0; 
            }
        } 
        return dp[m-1][n-1];        
    }
};
  ```
</div>
