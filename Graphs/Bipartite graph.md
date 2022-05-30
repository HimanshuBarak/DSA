<h2>Bipartite Graph</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/bipartite-graph/1)

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
  1. Similar to M-coloring problem Check that out
  2. For each vertex check its color 
  3. Assign the neighbour a diff color if its not possible to assign it than its not bipartite
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    bool bfs(vector<int> adj[],vector<int> &vis,vector<int> &col,int u){
        queue<int> q;
        q.push(u);
        col[u]=0;
        
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            int c = col[v]==1?0:1;
            for(auto x:adj[v])
            {
                if(col[x]==col[v])
                  return true;
                if(col[x]==-1)
                  col[x]=c;
                if(!vis[x]){
                    vis[x]=1;q.push(x);
                }
                  
            }
        }
        return false;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int> vis(V,0);
	    
	    vector<int> col(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	      if(!vis[i]){
	         if(bfs(adj,vis,col,i))
	           return false; 
	      }     
	      
	    }
	    return true;
	}

};
  ```
</div>
