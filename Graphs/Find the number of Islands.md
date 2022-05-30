<h2>Find the number of islands</h2>
<h3>Medium</h3><hr>
<div><p>
  Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 
</p>


[Problem Link](https://leetcode.com/problems/number-of-islands/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
<strong>Output:</strong> 1
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
  1. Check number of times dfs is executed
  2. If you dont want to maintian a vis array each time you visit a vertex make it zero
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
#define f first
#define s second
class Solution {
public:
     bool isvalid(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }
    void bfs(vector<vector<char>>& grid,int i,int j,int m,int n)
    {     
         queue<pair<int,int>> q;    
         q.push({i,j}); 
         int dx [] = {1,-1,0,0};
         int dy [] = {0,0,1,-1};
          
         while(!q.empty())
         {
             pair<int,int> p=q.front();
             q.pop();
             int x=p.f;int y=p.s;
            for(int i=0;i<4;i++)
            {
                if(isvalid(x+dx[i],y+dy[i],m,n) && grid[x+dx[i]][y+dy[i]]=='1')   
                   {
                       grid[x+dx[i]][y+dy[i]]='0';
                       q.push({x+dx[i],y+dy[i]});
                   }        
             }
         }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    bfs(grid,i,j,m,n);
                }
            }
        }
        return count;
    }
};
  ```
</div>
