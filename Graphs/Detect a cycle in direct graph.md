<h2>Detect cycle in a directed graph</h2>
<h3>Medium</h3><hr>
<div><p> Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


</p>




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
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
   Here check for each vertex 
   the vertext visited in each vertex
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool getCycle(vector<int> adj[],vector<int> &vis,vector<int> &dfs_vis,int v)
     {
         vis[v]=1;
         dfs_vis[v]=1;
        
         for(auto x:adj[v])
         { 
             //its important to return it here itself else kis aur vertex ke getcycle ki value store hojaegi idhr
             if(vis[x]==0){
                if(getCycle(adj,vis,dfs_vis,x))
                 return true;
             }
               
             else if(dfs_vis[x]==1)
               return true;
         }
         dfs_vis[v]=0;
         return false;
     }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
            vector<int> vis(V+1,0);
            vector<int> dfs_vis(V+1,0);
            for(int i=0;i<V;i++)
            {
                if(!vis[i])
                 {
                     if(getCycle(adj,vis,dfs_vis,i))
                       return 1;
                 }
            }
        return 0;    
    }
};


  ```
</div>
