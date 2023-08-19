<h2>No. of Ways to Arrive at a Destination</h2>
<h3>Medium</h3><hr>
<div><p>
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.  

 
</p>


[Problem Link](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, roads = [[1,0,10]]
     
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Dijikstra but you need to maintain a ways array also take care of the types
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  #define pInt pair<long long,int>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& t) {
        vector<vector<long long>> adj[n];
        for(int i=0;i<t.size();i++)
        {  
              adj[t[i][0]].push_back({t[i][1],t[i][2]}); 
              adj[t[i][1]].push_back({t[i][0],t[i][2]});  
        }
        int mod = (int)(1e9+7);
        priority_queue<pInt, vector<pInt>, greater<pInt>> pq;    //min heap
        vector<long long> dist(n,LONG_MAX); // NEED TO DO LONG MAX HERE
        vector<long long> ways(n,0);
        pq.push({0,0});
        dist[0]=0; // 0 is the starting node
        ways[0]=1;
        while(!pq.empty())
         {
            int v = pq.top().second;
            long long dis = pq.top().first;
            pq.pop(); 
            for(auto x:adj[v])
            {
                long long node = x[0];
                long long  wt = x[1];
                
                if(dist[node]>(long long)dist[v]+wt)
                {    
                  dist[node] = dist[v] +wt;
                  ways[node] = ways[v]%mod; // the number of ways the last element was reached will same number of ways to reach this element
                  pq.push({dist[node],node});
                }else if(dist[node]==(dis+wt))
                {
                    ways[node] = (ways[node]+ways[v])%mod;
                }
            }
         }
         return ways[n-1];
         
    }
};
  ```
</div>
