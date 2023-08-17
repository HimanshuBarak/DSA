

<h2> Prim's Algorithm </h2>


<h2> Algorithm </h2>

<pre>  
Concept => for each vertex we have to select an edge that has the min weight (among all the edges connected to the vertex)

1. Use a priority queue to get the next min wt edge 
2. Maintain a distance matrix for updating the distance of the each vertex during the MST
3. Visited array /node conatined in MST or not
4. Parent array to print the MST
</pre>

<h2> Code : </h2>

```c++

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // what we have done here is we started with any vertex and then for each vertex 
        // and then for each connected vertex we select the edge with minimum cost using
        // a min heap we keep doing this until we have connected all the vertex using n-1
        // such edges
        vector<int> vis(V,0);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        
        
         //dist matrix to store the distance 
        vector<int> dist(V,INT_MAX);
         //now we try to find out the parent o
        vector<int> parent(V,-1);
        pq.push({0,{0,-1}});
        dist[0]=0;
        int sum =0;
        while(!pq.empty())
        {
           pair<int,pair<int,int>> p = pq.top();
           pq.pop();
           int v = p.second.first;
           int dis = p.first;
           
           // vertex is alreday present and its associated min edges are already calculated 
           if(vis[v])
            continue;
            parent[v] = p.second.second;
            vis[v]=1;
            sum+=dis;
           
            for(auto x:adj[v])
            {
                if(!vis[x[0]])
                {   
                    pq.push({x[1],{x[0],v}});
                }
            }
        }
        
       
        
        for(int i=0;i<V;i++)
        cout<<parent[i]<<"  ";
        return sum;
    }
};

```
