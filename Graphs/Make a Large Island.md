<h2>Make a large Island </h2>
<h3> Hard </h3><hr>
<div><p>
 You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s. 

</p>


[Problem Link](https://leetcode.com/problems/making-a-large-island/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> grid = [[1,0],[0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1],[1,0]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Change the 0 to 1 and make the island bigger, only one island with area = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(n*n)
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. First bifuracte the existing in different components (you can use Disjoint Set for that 
  2. Simulatenously calculate the number of zeroes and their coordinates. If there are no zeroes just return the largest compnent
  3. If there are zero find out at which position when the 1 is inserted the largest element are connected
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   class DisjointSet{
  public:  
  vector<int> rank,parent,size;
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
   
  void unionBySize(int u,int v)
  {
      int pU = getParent(u);
      int pV = getParent(v);
// incase they both belong to the same parent no need to perform the union
      if(pU==pV)
       return; 
       // we attach smaller rank bith bigger to decrease the overall time in finding the parent
      if(size[pV]>size[pU])
      {
          parent[pU]=pV;
          size[pV]+=size[pU];
      }
      else if(size[pU]==size[pV])
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

class Solution {
public:
  
   bool isValid(int i,int j,int n)
   {
       if(i>=0 && j>=0 && i<n && j<n)
         return true;
       else
         return false;
   }
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int i,int j,DisjointSet &ds)
    {   
        int n=grid.size();
        vis[i][j]=1;  
        int node = n*i+j;
        int dir[5]= {-1,0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int x = i + dir[k];
            int y = j + dir[k+1];
            if(isValid(x,y,n) && !vis[x][y] && grid[x][y]==1)
            {
                int adjNode = x*n+y;

                if(ds.getParent(node)!=ds.getParent(adjNode))
                {
                    ds.unionBySize(node,adjNode);
                }
                dfs(grid,vis,x,y,ds);
            }
            
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        // we need to figure out the optimal minimum

        //we can first do bfs to already calculate the cooncted components
        int n =grid.size();
      
        DisjointSet ds(n*n);
        vector<pair<int,int>> zeroes;
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                dfs(grid,vis,i,j,ds);
                else if(!grid[i][j])
                  zeroes.push_back({i,j}); 
            }
        }
        int ans=0;
        //now all the existing 1's have been grouped and total zeroes are counted 
        // we can try out for each position and return the one with max position
        if(zeroes.size()==0)
        {
            for(int i=0;i<n*n;i++)
            {
                ans=max(ans,ds.size[i]);
            }
            return ans;
        }
       max O(nXn)
        for(auto k:zeroes)
        {
            int i = k.first;
            int j = k.second;
            int node = n*i+j;
            int dir[5]= {-1,0,1,0,-1};
            unordered_set<int> se;
            int tmp=1;
           
            for(int k=0;k<4;k++)
            {
                int x = i + dir[k];
                int y = j + dir[k+1];
                if(isValid(x,y,n) && grid[x][y]==1)
                { 
                  int adjNode = x*n+y;
                  int p =  ds.getParent(adjNode);
                
                  if(se.find(p)==se.end())
                  {
                      se.insert(p);
                      tmp+=ds.size[p];
                  }
                    
                }
                
            }
            ans=max(ans,tmp);

        }
        
        return ans;
    }
};
  ```
</div>
