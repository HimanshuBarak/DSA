<h2>Network Delay Time</h2>
<h3>Medium</h3><hr>
<div><p>
  You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 
</p>


[Problem Link](https://leetcode.com/problems/network-delay-time/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> times = [[1,2,1]], n = 2, k = 1
     
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Simple Dijikstra
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<vector<int>> adj[n+1];
        for(int i=0;i<t.size();i++)
        {  
              adj[t[i][0]].push_back({t[i][1],t[i][2]});  
        }

         priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    //min heap

         vector<int> dist(n+1,INT_MAX); 
         pq.push({0,k});
         dist[k]=0;
         while(!pq.empty())
         {
            int v = pq.top().second;
            pq.pop();
            
            for(auto x:adj[v])
            {
                int node = x[0];
                int wt = x[1];
                
                if(dist[node]>dist[v]+wt)
                {
                    dist[node] = dist[v]+wt;
                    pq.push({dist[node],node});
                }
            }
         }

         int ans=0;
         for(int i=1;i<=n;i++)
         {
             ans=max(ans,dist[i]);
         }

         return ans==INT_MAX?-1:ans;
    }
};
  ```
</div>
