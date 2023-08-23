<h2>Shortest Path in Undirected Graph</h2>
<h3>Medium</h3><hr>
<div><p>
  You are given an Undirected Graph having unit weight, 
  Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1)

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
 We can use simple BFS to solve this 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        // code here
        
    // we need to consider the case when the two nodes are not connected at all in that case the distance
    // will be -1
      
        
    vector<int> dist(n,-1);
    vector<int> vis(n,0);

  
    vector<vector<int>> adj(n);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vis[src]=1;
    dist[src]=0;

   
    queue<int> q;
    q.push(src);
   
    while(!q.empty())
    {  
           int v = q.front();
           q.pop();

           for(auto x:adj[v])
           {
               if(!vis[x])
               {
                   vis[x]=1;
                   dist[x]=dist[v]+1;
                   q.push(x);
               }
         }
        
    }

    return dist;
    }
};
  ```
</div>
