<h2>Strongly Connected Components (Kosaraju's Algo)</h2>
<h3> Medium</h3><hr>
<div><p>
  
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)

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
  1. find topoligical sort of the graph
	2. make the transpose of the graph
	3. find dfs of the reversed graph
	/* the reason we do this is once u rev all edges and perform dfs based on topological sort
	 each component will be a strongly connect component
	=> Strongly Connected Component(SCC) is a component in which each node can reach other all 
	nodes present in the component
   
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	//THE algorithm consist of 3steps
	
	
	void dfs(vector<int> adj[],vector<int> &vis,stack<int> &st,int v){
	    
	     vis[v]=1;
	     for(auto x:adj[v])
	     {
	         if(!vis[x])
	           dfs(adj,vis,st,x);
	     }
	     st.push(v);
	}
	
	void dfs(vector<int> adj[],vector<int> &vis,int v){
	     vis[v]=1;
	     for(auto x:adj[v])
	     {
	         if(!vis[x])
	           dfs(adj,vis,x);
	     }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
             dfs(adj,vis,st,i);
        }
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
        }
        
        int count=0;
        //creating a transpose of the graph (reversing the edges)
        vector<int> transp[V];
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
             transp[x].push_back(i);
        }
        
        while(!st.empty()){
            int v=st.top(); st.pop();
            if(!vis[v])
            {
                count++;
                dfs(transp,vis,v);
            }
        }
        return count;
    }
};
  ```
</div>
