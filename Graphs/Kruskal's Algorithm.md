
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

   class DisjointSet{
  vector<int> rank,parent,size;
  public:
  DisjointSet(int n)
  {
    // we declare the rank array of size n+1 incase there is 1 based indexin
    rank.resize(n+1);
    // intialize each node as a parent of iteself
    parent.resize(n+1);
    // for size array
    size.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
  }
  
  // function to create union of two components
  void unionByRank(int u,int v)
  {
      int pU = getParent(u);
      int pV = getParent(v);
// incase they both belong to the same parent no need to perform the union
      if(pU==pV)
       return; 
       // we attach smaller rank bith bigger to decrease the overall time in finding the parent
      if(rank[pV]>rank[pU])
      {
          parent[pU]=pV;
      }
      else if(rank[pU]==rank[pV])
      {
          rank[pU]++;
          parent[pV]=pU;
      }else
         parent[pV]=pU;
  }
  
  void unionBySize(int u,int v)
  {
      int pU = getParent(u);
      int pV = getParent(v);
// incase they both belong to the same parent no need to perform the union
      if(pU==pV)
       return; 
       // we attach smaller rank bith bigger to decrease the overall time in finding the parent
      if(rank[pV]>rank[pU])
      {
          parent[pU]=pV;
          size[pV]+=size[pU];
      }
      else if(rank[pU]==rank[pV])
      {
          size[pU]+=size[pV];
          parent[pV]=pU;
      }else
      {
           parent[pV]=pU;
           size[pU]+=size[pV];
      }
        
  }
  
  // function to find parent of a given node
  int getParent(int v)
  {
      if(parent[v]==v)
       return v;
      else
       return parent[v] = getParent(parent[v]); // here we are doing path compression so that next time we will find the parent in O(1) time
  }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
         // we first convert the adajaceny matrix to a vector of edges
         
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<V;i++)
         {
             for(auto x:adj[i])
             {  
                edges.push_back({x[1],{i,x[0]}}); 
             }
         }
         
        //we sort this matrix based on the weights
        sort(edges.begin(),edges.end());
        
        //intialize our disjoint set
        DisjointSet ds(V);
        int ans=0;
        for(int i=0;i<edges.size();i++)
        {
            pair<int,pair<int,int>> p;
            p=edges[i];
            
            if(ds.getParent(p.second.first)!=ds.getParent(p.second.second))
              ans+=p.first;
            
            ds.unionBySize(p.second.first,p.second.second);  
        }
        
        
        return ans;
    }
};
```
