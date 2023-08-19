<h2>Find the city with the Smallest Number of Neighbors at a threshold distance.</h2>
<h3> Medium</h3><hr>
<div><p>
 There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path. 
</p>


[Problem Link](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
<strong>Output:</strong> 3
<strong>Explanation:</strong> The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
     
<strong>Output:</strong> 0
<strong>Explanation:</strong> The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> n*n*n
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Simply apply Flowd Warshal algorithm
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        // we can simply use floyd warshal algorithm

        //we first create an adajacency matrix
        vector<vector<int>> adj(n,vector<int>(n,1e8));
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]][edges[i][1]]=edges[i][2];
            adj[edges[i][1]][edges[i][0]]=edges[i][2];
        }
       
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }

        //now we calculate the thing
        int ans=0, mini=INT_MAX;
        for(int i=0;i<n;i++)
        { int cnt=0;
          for(int j=0;j<n;j++)
           {
               if(i!=j && adj[i][j]<=thres)
                 cnt++;
           }
           if(cnt<=mini)
            {
                mini=cnt;
                ans=i;
            }
        }
        return ans;

        // we can also do this using bellman ford or dijikstra algorithm as well
    }
};
  ```
</div>
