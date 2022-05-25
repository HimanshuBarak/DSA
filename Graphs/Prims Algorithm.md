

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
        // code here
        //min heap
        priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        int ans=0;
        //dist matrix to store the distance 
        vector<int> dist(V,INT_MAX);
        dist[0]=0; //this will be our starting point
        //for printing the minimum spanning tree
        vector<int> parent(V,-1);
        //for marking the nodes contained in MST
        vector<int> mst(V,0);
        
        pq.push({0,0}); //pushing the first entry in the queue
        
        while(!pq.empty())
        {
            int v =pq.top().second;
           
            pq.pop();
            
            mst[v]=1;
            
            //adding the minimum edged neighbours
            for(auto x:adj[v])
            {
                int wt = x[1];
                int u =x[0];
                
                if(!mst[u] && wt<dist[u]) //if this edge is not in the mst and its weight is lesser
                  {
                      dist[u]=wt;
                      parent[u]=v;
                      pq.push({wt,u});
                  }
            }
        }
        //getting the final result
        for(int i=0;i<V;i++)
          ans+=dist[i];
        return ans;
    }
};

```
