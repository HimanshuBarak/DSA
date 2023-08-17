<h2>Disjoint Set</h2>
<h3>Medium</h3><hr>
<div><p>
  A  code for Disjoint Set with union done using rank as well as size

 
</p>


[Problem Link]()


<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(4)
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

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

int main() {
    // Write C++ code here
    
    DisjointSet ds(7);
    /*
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    */
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.getParent(3) == ds.getParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.getParent(3) == ds.getParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
    return 0;
}
  ```
</div>
