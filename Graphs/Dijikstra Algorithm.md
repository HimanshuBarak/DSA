<h2> Dijikstra algorithm </h2>


<p> Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.</p>


<h2> Algorithm </h2>

<pre>
 Main concept => for every vertex select the edge with the min weight and keep updating the dist matrix 
 1. Choose the starting point
 2. Choose the next vertex basd on min edge weight among all vistied vertex neighbours (repetitive step)
</pre>


<h2> Code </h2>

```c++
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dis (V,INT_MAX);
        dis[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        while(!pq.empty())
        {
          int node = pq.top().second;
          pq.pop();
          
          for(vector<int> x:adj[node])
          {
            int a_node = x[0];  //the adajacent node
            int wt = x[1];      //weight of the adajacent node 
           // if the distance of reaching the current vertex + this new edge is less update dist matrix
            if(dis[node] + wt < dis[a_node]){
                dis[a_node] = dis[node] + wt;
                pq.push({dis[a_node], a_node});
            }
          }
        }
        return dis;
    }
};

```
