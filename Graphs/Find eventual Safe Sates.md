<h2>Find eventual Safe States</h2>
<h3>Medium</h3><hr>
<div><p>
  There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 
</p>


[Problem Link](https://leetcode.com/problems/find-eventual-safe-states/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
   /*
           
            any node which is not a part of the cycle is part of the eventual safe state
            so we basically return all the nodes which don't form a cycle

            how do we do it
            in the detecty a cycel using dfs code 
            in the current visited vector if there is a cycle the currvis node remains
            true else it will change to false
            the node which contains false are the ones that don't form a cycle
        */
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:

   bool dfs(vector<vector<int>>& graph, int i,vector<int> &vis,vector<int> &currVis)
   {
           vis[i]=1;
           currVis[i]=1;
           for(auto x:graph[i])
           {
               if(!vis[x])
               {
                   if(dfs(graph,x,vis,currVis))
                     return true;
               }else if(currVis[x])
               {
                   return true;
               }
           }
           currVis[i]=0;
           return false;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       
        int n = graph.size();
        vector<int> res;
        vector<int> currVis(n,0);
        vector<int> vis(n,0);
        for(int i=0;i<graph.size();i++)
        {
            if(!vis[i])
            {
                dfs(graph,i,vis,currVis);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(!currVis[i])
              res.push_back(i);
        }
        return res;

    }
};
  ```
</div>
