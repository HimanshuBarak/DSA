<h2>Bridge Edge in a Graph</h2>
<h3></h3><hr>
<div><p>
  
Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1)

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
  1. Quite tricky watch strivers video but the amin gist is
  2. U do dfs while maintianing two arras tin[] and low[] intializie both to time
  3. update value of low to lowest of its adajacent
  4. and for a vertex if low[u] > tin[v] edge is a cut edge
  </pre>
  <h2> Solution </h2>
  
  ``class Solution
{
	public:
	
	bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &low,int parent,vector<int> &tin,int v,int c,int d,int time)
	{
	    vis[v]=1;
	    
	    tin[v]=low[v]=time++;
	    
	    for(auto x:adj[v])
	    {   
	        if(x==parent)
	         continue;
	        if(!vis[x])
	        {
	            //first do dfs
	            dfs(adj,vis,low,v,tin,x,c,d,time);
	             
	            low[v]=min(low[v],low[x]);  //min time to reach that edge is there of adajacent 
	            if(v==c &&x==d &&low[x]>tin[v])
	              return true;
	        }else
	        low[v]=min(low[v],tin[x]);
	    }
	    
	    return false;
	}
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        
        //we only need to check for the component 
        
        vector<int> low(V,-1);
        vector<int> tin(V,-1);
        vector<int> vis(V,0);
        
        return dfs(adj,vis,low,-1,tin,c,c,d,1);
        
    }
};` c++ 

  ```
</div>
