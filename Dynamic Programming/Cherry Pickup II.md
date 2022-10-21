<h2>Cherry Pickup</h2>
<h3>Hard</h3><hr>
<div><p>
  You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.

 
</p>


[Problem Link](https://leetcode.com/problems/cherry-pickup-ii/)

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
       //Recursive Solution   O(n*m*m)*9
     class Solution {
public:
    
    int solve(int i,int j1,int j2,int n,int m,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
    {  
        //incase of invalid location
        if(j1<0 || j2<0 ||j2>=m ||j1>=m)
            return -1e8; 
        if(i==n-1)
        {
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
          return dp[i][j1][j2];    
        
        int ans=0;
        
        for(int x=-1;x<=1;x++)
        {
         for(int y=-1;y<=1;y++)
         {
             int value=0;
            if(j1==j2)
              value = grid[i][j1];
            else
              value =grid[i][j1]+grid[i][j2];
            
          ans =max(ans,value+solve(i+1,j1+x,j2+y,n,m,grid,dp)) ; 
         }
        }
        return dp[i][j1][j2]= ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,n,m,grid,dp);
    }
};
  
  //Tabulation 
   int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        
      
        //base case
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                    dp[n-1][j1][j2]=grid[n-1][j1];
                else
                   dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2]; 
            }
        }
        
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                      int ans=0;
                    for(int x=-1;x<=1;x++)
                    {
                     for(int y=-1;y<=1;y++)
                     {
                         int value=0;
                        if(j1==j2)
                          value = grid[i][j1];
                        else
                          value =grid[i][j1]+grid[i][j2];
                      if(j1+x>=0 && j1+x<m && j2+y>=0 && j2+y<m)
                          value+=dp[i+1][j1+x][j2+y];
                      else
                          value+=(-1e8);
                      ans =max(ans,value) ; 
                     }
                    }
                 dp[i][j1][j2]=ans;   
              }
            }
        }
        return dp[0][0][m-1];
        
    }
};
  ```
</div>
