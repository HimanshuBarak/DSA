<h2> 01 Matrix </h2>
<h3>Medium</h3><hr>
<div><p>
  Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 
</p>


[Problem Link](https://leetcode.com/problems/01-matrix/description/)

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
  #define f first
#define s second
class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//shortest paths-unweighted graph---->bfs(very standard)
//but usually 1 source node---minimum distance from that particular node
//but here multiple source nodes
//so push all of them first
//WHY???
//WHEN WE POP AND EXPLORE WE ARE DOING SO IN INCREASING ORDER OF THEIR LEVELS
//SO WHEN WE DISCOVER A NODE FIRST WE ARE EXPLORING IT FROM MINI POSSIBLE LEVEL NODE THAT IT IS CONNECTED TO
//first the source..then level 1 nodes..then level 2 and so on
//here the case is there are many level 0 nodes
//so push all of them first!!!

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> res(n,vector<int>(m,-1));
       /*
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {  
                if(!mat[i][j])
                {   res[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }
         
        while(!q.empty())
        {  
            int i = q.front().f.f;
            int j = q.front().f.s;
            int cost = q.front().s;
            q.pop();
            int dir[5] = {-1,0,1,0,-1};
        
            for(int k=0;k<4;k++)
            {
                int x = i + dir[k];
                int y = j + dir[k+1];
                // since we are using bfs we can be sure that the first node that the first time the //node is traversed it will be the shortest distance only
                
                if(x>=0 && y>=0 && x<n && y<m && res[x][y]==-1)
                {  
                    res[x][y] =cost+1;
                    q.push({{x,y},cost+1}); 
                } 
           } 
        }
      */
      // a more simple version of this could be that we can store the distance in the res matrix itself
      // no need to maintain the cost variable

      queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {  
                if(!mat[i][j])
                {   res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        // Time Complexity is => O(n*m)  
        while(!q.empty())
        {  
            int i = q.front().f;
            int j = q.front().s;
           
            q.pop();
            int dir[5] = {-1,0,1,0,-1};
        
            for(int k=0;k<4;k++)
            {
                int x = i + dir[k];
                int y = j + dir[k+1];
                // since we are using bfs we can be sure that the first node that the first time the //node is traversed it will be the shortest distance only
                
                if(x>=0 && y>=0 && x<n && y<m && res[x][y]==-1)
                {  
                    res[x][y] = res[i][j]+1;
                    q.push({x,y}); 
                } 
           } 
        } 
        return res;
    }
};
  ```
</div>
