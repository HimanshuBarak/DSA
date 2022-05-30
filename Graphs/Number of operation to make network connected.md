<h2>Number of Operations to make network connected</h2>
<h3>Medium</h3><hr>
<div><p>
  
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 
 
</p>


[Problem Link](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> n = 4, connections = [[0,1],[0,2],[1,2]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Remove cable between computer 1 and 2 and place between computers 1 and 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p> Same as that of bfs/dfs
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. check no. of edges
  2. Find total components using dfs =>this is equal to the number of components that need to be connected
  3. return these and thats your answer
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 

  class Solution {
public:
    /* Algorithm Can be divided into 2 major parts 
     Path1 : Finding if there enough cables
     
     Each edge in a graphs is a cable 
     The size of the list gives us the total edges(cables)
     if this is less that n-1 no feasible answer
     
     Part 2 => to find the no. of operations required => find the total no. of disconnected components
     
     Use dfs/bfs 
    
    */
    
    void dfs(vector<vector<int>> &adj,vector<int> &vis,int v){
        vis[v]=1;
        for(auto x:adj[v])
        {
            if(!vis[x])
                dfs(adj,vis,x);
        }
    }
    int makeConnected(int n, vector<vector<int>>& con){   
        vector<int> vis(n,0);
        
        if(con.size()<(n-1))
            return -1;
        
        
        //making a adajaceny list
        
        vector<vector<int>> adj(n);
        
        for(auto i:con)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        //looping through for that dfs thing
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                
                dfs(adj,vis,i);
                count++;
            }
        }
        return count-1;
    }
    
};
  ```
</div>
