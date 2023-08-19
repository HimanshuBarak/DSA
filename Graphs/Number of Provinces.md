<h2>Number of Provinces</h2>
<h3>Medium</h3><hr>
<div><p>
 There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces. 

 
</p>


[Problem Link](https://leetcode.com/problems/number-of-provinces/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> isConnected = [[1,1,0],[1,1,0],[0,0,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> isConnected = [[1,0,0],[0,1,0],[0,0,1]]
     
<strong>Output:</strong> 3
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
    void dfs(int i,vector<vector<int>>& adj,vector<int> &vis)
    {
        vis[i]=1;
        for(int j=0;j<adj.size();j++)
        {
            if(!vis[j] && adj[i][j])
            {
                dfs(j,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
      // this can be solved using a simple dfs traversal    
      // the numnber of dfs traversal that are executed will be the numbero f provinces
      // also here the vertex or province number is strting from 0
      
      int n = adj.size();
      vector<int> vis(n+1,0);
       int cnt=0;
       for(int i =0;i<n;i++)
       {
           if(!vis[i])
           {
               cnt++;
               dfs(i,adj,vis);
           }
       }

       return cnt;
    }
};
  ```
</div>
