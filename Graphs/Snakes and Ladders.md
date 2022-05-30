<h2>Snakes and Ladders</h2>
<h3>Medium</h3><hr>
<div><p>
  
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.
 
</p>


[Problem Link](https://leetcode.com/problems/snakes-and-ladders/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
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
  1. Convert the board into a 1D array of n*n.
  2. Do BFS
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n=board.size();
        
        int  arr[n*n+1] ; //coz we will be storing from index 1  
        
        //storing values in the array
        int dest=n*n;
        int index=1;
        int i=n-1,j=0,inc=1;
        while(index<=dest)
        {
            arr[index++]=board[i][j];
            if(inc==1 && j==n-1)
            { //end of the row reached change row and now decrement j value
                i--;
                  inc=-1;
            }else if(inc==-1 && j==0)
            {
                //end of row reached change row and decrement j value
                i--;inc=1;
            }else
                j+=inc;
        }
       
        //array made now do simple bfs to get the path
        vector<int> vis(dest+1,0);
        queue<int> q;
        int start = arr[1]>-1?arr[1]:1;
        q.push(start);
        vis[1]=1; 
        int move=0;
        while(!q.empty()){
            int m=q.size();
            
            while(m-->0)
            {
                int cur = q.front();
                q.pop();
               // cout<<cur<<"-->";
                if(cur==dest)
                    return move;
                //visit its size neighbours
                for(int i=cur+1;i<=min(cur+6,dest);i++)
                {
                    int step = arr[i]>-1?arr[i]:i;
                    if(!vis[step])
                    {
                        vis[step]=1;
                        
                        q.push(step);
                    }
                }
            }cout<<endl;
            move++;
        }
        return -1;
    }
};
  ```
</div>
