<h2> Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.</h2>

<h3> Algorithm </h3>
```
1. Just do simple dfs and store it in stack ,its basically reverse of a dfs which can be accomplished using a stack

```

``` c++
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(vector<int> adj[],vector<int> &vis,int v,stack<int> &st)
	{
	    vis[v]=1;
	    for(auto x:adj[v])
	    {
	        if(!vis[x])
	          dfs(adj,vis,x,st);
	    }
	    
	    st.push(v);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<int> vis(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	         dfs(adj,vis,i,st);
	    }
	    vector<int> res;
	    while(!st.empty())
	    {
	        res.push_back(st.top());
	        st.pop();
	    }
	    
	    return res;
	}
};

```
