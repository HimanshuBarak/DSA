<h2>Sudoku Solver</h2>
<h3>Hard</h3><hr>
<div><p>
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.  

 
</p>


[Problem Link](https://leetcode.com/problems/sudoku-solver/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>  board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
<strong>Output:</strong> [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],
["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
<strong>Explanation:</strong> The input board is shown above and the only valid solution is shown below:
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
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
    class Solution {
public:
    //khatarnak question h bahi
    
    bool isValid(vector<vector<char>>& board,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c) //checks left to right
                return false;
            if(board[i][col]==c) //checks up to down
                return false;
            
            //check in the 3x3 grid
            if(board[3*(row/3)+ i/3][3*(col/3)+ i%3]==c)
                return false;
            //row / by 3 coz in a grid we need to change rwo thrive column ko 9 times so %
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.') //if its empty try filling it
                {
                    for(char ch='1';ch<='9';ch++){
                       if(isValid(board,i,j,ch)) {
                          board[i][j]=ch;
                        
                        if(solve(board))
                            return true;
                        else
                            board[i][j]='.'; 
                       }         
                    }
                    return false;
                }
            }
        }
        return true; //everything is filled than only this will get executed
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
  ```
</div>
