<h2> Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.</h2>

<h3> Algorithm </h3>
<pre>
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

1. Just do simple dfs and store it in stack ,its basically reverse of a dfs which can be accomplished using a stack

2. For BFS approach we maintain array named indegree(for each node this contains the number of incoming edges ) now we push all the vertex with indegree 0
   and as we visit the vertex we decrease the indegree of them and if it becomes zero we push it in the queue
Some sample problems would be
  1. Minimum time taken by each job to be completed given by a Directed Acyclic Graph
  2. Find whether it is possible to finish all tasks or not from given dependencies => for this one you actually need to check for a cycle if its there not possible else possible
</pre>


<h3> Code </h3>

```c++

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


//BFS approach 
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	   vector<int> indeg(V,0);
	  
	   vector<int> res;
	   //filling the indegree matrix
	   for(int i=0;i<V;i++)
	   {
	       for(auto x:adj[i])
	       {
	           indeg[x]++;
	       }
	   }
	   queue<int> q;
	   // finding vertexes with 0 indegree
	   
	   for(int i=0;i<V;i++)
	   {
	       if(indeg[i]==0)
	       {
	           q.push(i); 
	       }
	   }
	   while(!q.empty())
	   {
	       int v =q.front();
	       q.pop();
	       res.push_back(v);
	       for(auto x:adj[v])
	       {
	           indeg[x]--;
	           if(indeg[x]==0)
	           {
	               q.push(x); //indeg[x]--;
	           }
	       }
	   }
	   return res;
	}
};
```
