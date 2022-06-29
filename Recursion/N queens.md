<h2>N queens</h2>
<h3>Hard</h3><hr>
<div><p>
  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
</p>


[Problem Link](https://leetcode.com/problems/n-queens/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> 4
<strong>Output:</strong> [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
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
       Brute Force Approach Bhai
  class Solution {
public:
    //this is actually a really good problem
    
    bool isSafe(int row,int col ,vector<string> board,int n)
    {
        int i=row,j=col;
        //no need to check for column
        //check for the row
        while(j>=0)
        {
            if(board[row][j]=='Q')
                return false;
            j--;
        }
        //upper diagonal
        j=col;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')
                return false;  
            i--;j--;
        }
        //lower left diagonal
        i=row,j=col;
         while(i<n && j>=0)
        {
            if(board[i][j]=='Q')
                return false;  
            i++;j--;
        }  
        return true;
    }
    
    void solve(vector<vector<string>> &res,int col ,vector<string> &board,int n){
        if(col==n)
        {  //successfully placed n queens ,so save ans and end
            res.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {   //if its possible to place the queen on the board place it else move on
            if(isSafe(row,col,board,n)){
                board[row][col]='Q'; //queen placed
                solve(res,col+1,board,n);
                board[row][col]='.'; //queen removed
            }
        }
    }
    
        
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string s(n,'.');
        //creating the board
        for(int i=0;i<n;i++)
        {
            board.push_back(s);
        }
        
        //now solving for those fucking queens
        solve(res,0,board,n);
        return res;
    }
};
                             
                             //Optimal Approach
      void solve(vector<vector<string>> &res,int col ,vector<string> &board,int n,vector<int> &leftrow,vector<int> &up_diag,vector<int> &low_diag){
        if(col==n)
        {  //successfully placed n queens ,so save ans and end
            res.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {   //if its possible to place the queen on the board place it else move on
            if(leftrow[row]==0 && up_diag[n-1+col-row]==0 && low_diag[row+col]==0){
                board[row][col]='Q'; //queen placed
                leftrow[row]=1;
                up_diag[n-1+col-row]=1;
                low_diag[row+col]=1;
                solve(res,col+1,board,n,leftrow,up_diag,low_diag);
                 leftrow[row]=0;
                up_diag[n-1+col-row]=0;
                low_diag[row+col]=0;
                board[row][col]='.'; //queen removed
            }
        }
    }
    
        
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string s(n,'.');
        //creating the board
        for(int i=0;i<n;i++)
        {
            board.push_back(s);
        }
        vector<int> leftrow(n,0);
        vector<int> up_diag(2*n-1,0);  
        vector<int> low_diag(2*n-1,0); //to fill this use n- col-row
        //now solving for those fucking queens
        solve(res,0,board,n,leftrow,up_diag,low_diag);
        return res;
    }                       
  ```
</div>
