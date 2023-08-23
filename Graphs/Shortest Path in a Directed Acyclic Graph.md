<h2>Shortest Path in a Directed Graph</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 4, M = 2 edge = [[0,1,2],[0,2,1]
<strong>Output:</strong> 0 2 1 -1
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> N = 6, M = 7
edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
     
<strong>Output:</strong> 0 2 3 6 1 5
<strong>Explanation:</strong> Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
Shortest path from 0 to 4 is 0->4 with edge weight 1.
Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   class Solution {
  public:
     
     //this function will give us the topological sort of the graph
     void topoSort(int node, vector<pair<int, int>> adj[],vector<int> &vis, stack <int> & st) {
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }
    
    //now for shortest path 
     vector<int> shortestPath(int n,int M, vector<vector<int>>& edges){
       
         // Time Complexity => O(V+E)
         
        /*
          why do we use toposort here?
          
           topological sort arranges the vertices in increasing order of their indegree.
           meaning we are processing index based on reachibilty (how quickly/easily it is reachable)
           
           for a topo sort order 
           
           6 5 4 0 1 
           
           at 5 we are sure that all the nodes that can reach 5 their shortest diatance is already calculated
        
        */
        vector<int> dist(n,1e9);
        vector<int> vis(n,0);
        stack<int> st;
        
        
         vector<pair<int, int>> adj[n];
         for(int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt}); 
          }
        /*
        
        but what if our source node is not on top? well in that case
        the dedault distance will not change it will remain 1e9 because
         x + 1e9 > 1e9 for evey positive value of x
        
        when the source node is encountered that fistance will start to change because
        the dist[src]=0 and hence 0 +x will be less than 1e9 
        */
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            topoSort(i,adj,vis,st);
        }
       dist[0]=0; // here we are taking source node to be zero but in truth it can be any node    
       while(!st.empty())
       {
           int v = st.top();
           st.pop();
           
           for(auto x:adj[v])
           {   
               int node =x.first;
               int wt = x.second;
               if(dist[node]>dist[v]+wt)
               {
                   dist[node] = dist[v]+wt;
               }
           }
       }
       for(int i=0;i<n;i++)
        {
            if(dist[i]==1e9)
            dist[i]=-1;
        }
       
        return dist; 
    }
};
  ```
</div>
