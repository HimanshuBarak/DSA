
<h2> Kruskal's Algorithm </h2>


<h2> Algorithm </h2>
<pre>
 Concept : keep on picking up the min weight edge as long as it doesn't form a cycle
 
 to ensure it doesnt' form  a cycle we use a disjoint set 
 if the parent of two nodes are same they willl form a cycle hence dont pick that edge
 use a struct to define the datatype
 
 
</pre>

<h2> Code </h2>

```c++
struct node{
    int u;
    int v;
    int wt;
    
    node(int first,int second ,int weight)
    {
        v=first;
        u=second;
        wt=weight;
    }
};

//for sorting the node array
bool comp(node a,node b)
{
   return a.wt<b.wt;   
}
//for finding the parent
int findpar(int v ,vector<int> &parent)
{
    if(parent[v]==v)
      return v;
    else
     return parent[v] = findpar(parent[v],parent); //for path compression as it searches it updates too
}
void unionn(int u,int v,vector<int> &rank,vector<int> &parent)
{    u=findpar(u,parent); //getting the parent
     v=findpar(v,parent);
    if(rank[u]<rank[v])
      parent[u]=v;
    else if(rank[v]<rank[u])
      parent[v]=u;
    else
    {
        parent[u]=v; rank[v]++;
    }
}
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	// 0 => pe node 1=>pe weight h thik haiiii
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //for finding parent so that the cycle is not formed 
        vector<int> parent(V);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        vector<int> rank(V,0);
        int cost=0;
        vector<node> edges;
        vector<pair<int,int>> mst;
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                edges.push_back(node(i,x[0],x[1]));
            }
        }
        sort(edges.begin(),edges.end(),comp);
        
        for(auto edge:edges)
        {
            if(findpar(edge.v,parent)!=findpar(edge.u,parent))
            {
                unionn(edge.v,edge.u,rank,parent);
                mst.push_back({edge.v,edge.u});
                cost+=edge.wt;
            }
        }
        return cost;
    }
};

```
