<h2>Path with MinimumEffort</h2>
<h3>Medium </h3><hr>
<div><p>
  
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
 
</p>


[Problem Link](https://leetcode.com/problems/path-with-minimum-effort/description/)

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
  class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& ht) {
        /*
        
        we will do dikstra 
        we will select the neighborinh node with the least common difference 
        we will store the ans as well 
        
        if we use prioirty queue with this it will be more efficient
        ElogV
        */

        int n =ht.size();
        int m =ht[0].size();
        vector<int> dir{-1,0,1,0,-1};
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e8));
        q.push({{0,0},0});
        dist[0][0]=0;
        while(!q.empty())
        {
          int i = q.front().first.first;
          int j = q.front().first.second;
          int effort = q.front().second;
          q.pop();
          for(int k=0;k<4;k++)
          {
              int x = i + dir[k];
              int y = j + dir[k+1];

              if(x>=0 && x<n && y>=0 && y<m)
              {
                  int z = abs(ht[i][j]-ht[x][y]);
                  int e = max(effort,z);
                  if(e<dist[x][y])
                  {
                      dist[x][y]=e;
                      q.push({{x,y},e});
                  }
              }  
          }
        }

        return dist[n-1][m-1];

// with priority queue the the time complexity becomes ElogV
int n =ht.size();
        int m =ht[0].size();
        vector<int> dir{-1,0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
       // queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e8));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty())
        {
          int i = pq.top().second.first;
          int j = pq.top().second.second;
          int effort = pq.top().first;
          pq.pop();
          for(int k=0;k<4;k++)
          {
              int x = i + dir[k];
              int y = j + dir[k+1];

              if(x>=0 && x<n && y>=0 && y<m)
              {
                  int z = abs(ht[i][j]-ht[x][y]);
                  int e = max(effort,z);
                  if(e<dist[x][y])
                  {
                      dist[x][y]=e;
                      pq.push({e,{x,y}});
                  }
              }  
          }
        }
    }
};
  ```
</div>
