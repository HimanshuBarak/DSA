<h2>Number of Enclaves</h2>
<h3>Medium</h3><hr>
<div><p>
  You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 
</p>


[Problem Link](https://leetcode.com/problems/number-of-enclaves/description/)

<p>&nbsp;</p> 
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
     
<strong>Output:</strong> 0
<strong>Explanation:</strong> All 1s are either on the boundary or can reach the boundary.
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

     void DFS(vector<vector<int>>& mat,int i,int j,int n,int m)
    {
       
        mat[i][j]=0;

         int dir[5] = {-1,0,1,0,-1};
        
            for(int k=0;k<4;k++)
            {
                int x = i + dir[k];
                int y = j + dir[k+1];
                if(x>=0 && y>=0 && x<n && y<m && mat[x][y]==1)
                {  
                   DFS(mat,x,y,n,m);
                } 
           } 
    }
    int numEnclaves(vector<vector<int>>& board) {
        
         int n = board.size();
         int m = board[0].size();
         

        // ones other then all the boundary ones and all the ones that are connected to this boundary ones
        // will give us the answer

        // we can solve this using boundary dfs

        //Moving over first and last row         
       for(int i=0; i<n; i++) {
         if(board[i][0] == 1)
             DFS(board, i, 0, n,m);
         if(board[i][m-1] == 1)
             DFS(board, i, m-1, n, m);
       }
        
        
     //Moving over first and last row   
     for(int j=0; j<m; j++) {
         if(board[0][j] == 1)
             DFS(board, 0, j, n, m);
         if(board[n-1][j] == 1)
             DFS(board, n-1, j, n, m);
     }
       int ones =0; 
          
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
              {  
                  if(board[i][j]==1)
                    ones++;
              }
          }
       return ones;  
    }
};
  ```
</div>
