<h2>Most Stones Removed with Same Row or Column</h2>
<h3>Medium</h3><hr>
<div><p>
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
</p>


[Problem Link]()

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
     
<strong>Output:</strong> 3
<strong>Explanation:</strong> One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(n*n)
  
<strong>Space:</strong> 
  <h2> Intuition </h2>
 <pre>
   //we can solve it using a disjoint set

       // we need to do this using union find
       // one possible way is we can perform union find on the index itself 
       // the time complexity for this solution will be O(n^2)

       // now our bottleneck here is the nested loop doing the union
       // perhasphs we can use a map to reduce the time complexity here
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
    int removeStones(vector<vector<int>>& stones) {
       
       int n =stones.size();
       
       DisjointSet ds(n);

       for(int i=0;i<n;i++)
       {
           for(int j=0;j<i;j++)
           {
              if(stones[j][0]==stones[i][0] || stones[j][1]==stones[i][1])
              {
                  ds.unionBySize(i,j);
              }
           }
       }
       int cnt=0;
       for(int i=0;i<n;i++)
       {
           if(ds.parent[i]==i)
            cnt++;
       }

       return n-cnt;
    }
};
  ```
</div>
