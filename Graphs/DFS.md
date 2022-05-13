
<h1> DFS of a Graph </h1>


``` c++

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfshelper(vector<int> adj[], vector<int> &vis,vector<int> &res, int v)
    {
        res.push_back(v);
        vis[v]=1;
        for(auto x:adj[v])
        {
            if(vis[x]==0)
                dfshelper(adj,vis,res,x);
            
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0); //defining the visited 
        vector<int> res;
        
        dfshelper(adj,vis,res,0);
        
        return res;
    }
};

```

