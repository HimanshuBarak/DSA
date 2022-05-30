<h2>Detect cycle in an undirected graph </h2>
<h3>Medium</h3><hr>
<div><p> 
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
  Do simple dfs and check if any vertex is being revisited also (exclude the parent when traversing the neighbours ) 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
  public:
  
   bool checkCycle(vector<int> adj[],vector<int> &vis,int v, int prev)
    {
        vis[v]=1;
        
        for(auto x:adj[v])
        {
            
            if(!vis[x]){
              if(checkCycle(adj,vis,x,v))
               return true;  
            }else if(x!=prev)
              return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++)
        {   
            if(!vis[i]){
              if(checkCycle(adj,vis,i,-1))
              return true; 
            }
           
        }
        return false;
    }
};
  ```
</div>
