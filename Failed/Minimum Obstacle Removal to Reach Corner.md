<h2>Minimum Obstacle Removal to Reach Corner</h2>
<h3>Hard</h3><hr>
<div><p> You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
<pre>
0 represents an empty cell,
1 represents an obstacle that may be removed.
</pre>
You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> grid = [[0,1,1],[1,1,0],[1,1,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
It can be shown that we need to remove at least 2 obstacles, so we return 2.
Note that there may be other ways to remove 2 obstacles to create a path.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
  This is 0-1 BFS (watch luv video to better understand it
  
  Basically we transport the graph into a weighted graph with weights being 1(for obstacles) and 0 (no obstacles) using this we do simple bfs where
  we use deque to evaluate first the edges with weight 0 and 1 later
  This is faster than dijikstra
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    //this can be solved using 0-1 bfs
    /*assume a graph with edge weight 0(no obstacles) and edge weights(1) with obstacles */
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //0-1 bfs supremacy
        
        //step1 => define an array for the direction of traversal
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        
       //maintain a distance matrix with intial distance of INT_max
      vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        
        //deque is used for 0 we consider it of same level push front for 1 push back
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        
        while(!dq.empty())
        {
            pair<int,int> p=dq.front();
            int x =p.first;
            int y= p.second;
            dq.pop_front();
            
            for(auto i:dir)
            {
                int nx =x+i.first;
                int ny =y +i.second;
                //check if the coordinate is valid or not
                if(nx<0 || ny<0 || nx>m-1 || ny>n-1)
                    continue;
                if(dist[x][y]+grid[nx][ny] <dist[nx][ny])
                {
                   
                    dist[nx][ny] =dist[x][y]+grid[nx][ny];
                     if(grid[nx][ny])            // if 1 push at back
                         dq.push_back({nx,ny});
                     else                        //if 0 push at front
                         dq.push_front({nx,ny});
                } 
            }
        }
      return  dist[m-1][n-1];
    }
};
  ```
</div>
