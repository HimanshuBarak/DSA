<h2>Rotting Oranges </h2>
<h3>Medium</h3><hr>
<div><p>
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.  

 
</p>


[Problem Link](https://leetcode.com/problems/rotting-oranges/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> grid = [[2,1,1],[1,1,0],[0,1,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[2,1,1],[0,1,1],[1,0,1]]
     
<strong>Output:</strong> -1
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(N^2)
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
 /*
           Here is the algorithm we will need to do Multisource BFS from all the rotten oranges:
          
          We can do this in the following way:
           First we store all the rotten oranges in the queue along with total count of fresh oranges 
           if the count is zero we can quit our loop
           and store the bfs step
        */
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
#define f first
#define s second
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //we fill try to do a simple bfs 

       
       
        int dir[5] = {-1,0,1,0,-1};
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh=0; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                  q.push({i,j});
                if(grid[i][j]==1)
                  fresh++;  
            }
        }
       
        int ans=0;
        if(!fresh)
          return 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
             int i = q.front().f;
             int j = q.front().s;
             q.pop();
            
             
             // traversing in all 4 directions 
             for(int k=0;k<4;k++)
             {
                 int x = i+dir[k];
                 int y = j+dir[k+1];

                 if(x>=0 && y>=0 && x<n && y<m &&  grid[x][y]==1)
                 {   grid[x][y]=2;
                     q.push({x,y});
                     fresh--;
                 }
             }  
            }
            ans++;
            if(!fresh)
             break;

        }
        return fresh?-1:ans;
    }
};
  ```
</div>
