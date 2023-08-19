<h2> Surrounded Regions </h2>
<h3> Medium </h3><hr>
<div><p>
  Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

</p>


[Problem Link](https://leetcode.com/problems/surrounded-regions/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
<strong>Output:</strong>  [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
<strong>Explanation:</strong>  Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>  board = [["X"]]
     
<strong>Output:</strong> [["X"]]
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
    void DFS(vector<vector<char>>& mat,int i,int j,int n,int m)
    {
       
        mat[i][j]='.';

         int dir[5] = {-1,0,1,0,-1};
        
            for(int k=0;k<4;k++)
            {
                int x = i + dir[k];
                int y = j + dir[k+1];
                if(x>=0 && y>=0 && x<n && y<m && mat[x][y]=='O')
                {  
                   DFS(mat,x,y,n,m);
                } 
           } 
    }
    void solve(vector<vector<char>>& board) {  
         

          int n = board.size();
          int m = board[0].size();
         
    //We will use boundary DFS to solve this problem
        
    // Let's analyze when an 'O' cannot be flipped,
    // if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board
        
      //consider these two cases for clarity :
      /*
        O's won't be flipped          O's will be flipped
        [X O X X X]                   [X X X X X]     
        [X O O O X]                   [X O O O X]
        [X O X X X]                   [X O X X X] 
        [X X X X X]                   [X X X X X]
      
      So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
      
      */
        
      //Steps to Solve :
      //1. Move over the boundary of board, and find O's 
      //2. Every time we find an O, perform DFS from it's position
      //3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
      //4. After all DFSs have been performed, board contains three elements,#,O and X
      //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      //6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
      
        
  
          
    //Moving over first and last row         
       for(int i=0; i<n; i++) {
         if(board[i][0] == 'O')
             DFS(board, i, 0, n,m);
         if(board[i][m-1] == 'O')
             DFS(board, i, m-1, n, m);
       }
        
        
     //Moving over first and last row   
     for(int j=0; j<m; j++) {
         if(board[0][j] == 'O')
             DFS(board, 0, j, n, m);
         if(board[n-1][j] == 'O')
             DFS(board, n-1, j, n, m);
     }
        
          
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
              {  
                  if(board[i][j]=='O')
                    board[i][j]='X';
                  else if(board[i][j]=='.')
                    board[i][j]= 'O';  
              }
          }
         
          
    }
};
  ```
</div>
