<h2>Cheapest Flight within K stops</h2>
<h3>Medium</h3><hr>
<div><p>
  
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
 
</p>


[Problem Link](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
<strong>Output:</strong> 700
<strong>Explanation:</strong> The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
     
<strong>Output:</strong> 200
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
   
           we will use simple dijikstra again here
           but our queue will of a differnt kind
        
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
 class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flt, int src, int dst, int k) {
       
        vector<vector<int>> adj[n];
        for(int i=0;i<flt.size();i++)
        {  
              adj[flt[i][0]].push_back({flt[i][1],flt[i][2]});  
            
        }

        queue<pair<int,pair<int,int>>> q;
        // make adajaceny list


        vector<int> dist(n,1e8);
        dist[src]=0;
        q.push({0,{src,0}});
        
         while(!q.empty())
        {
           int stop= q.front().first;
           int v = q.front().second.first;
           int cost = q.front().second.second;
           q.pop();
           if(stop >k)
            continue;
           for(auto x:adj[v])
           {
               int node = x[0];
               int wt =x[1];
               // here we use stop<=k because we don't count destination as a stop
               if(dist[node]>cost+wt && stop<=k)
               {
                   dist[node]=cost+wt;
                   q.push({stop+1,{node,cost+wt}});
               }
           }
        } 
       
        return dist[dst]==1e8?-1:dist[dst];
    }
};
  ```
</div>
