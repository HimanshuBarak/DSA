<h2>Course Schedule II</h2>
<h3>Medium</h3><hr>
<div><p>
  There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 
</p>


[Problem Link](https://leetcode.com/problems/course-schedule-ii/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> numCourses = 2, prerequisites = [[1,0]]
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
     
<strong>Output:</strong> [0,2,1,3]
<strong>Explanation:</strong> There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
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
  class Solution {
public:
  vector<int> findOrder(int V, vector<vector<int>>& preq) {
      queue<int> q;
	    vector<int> res;
	    vector<int> indeg(V,0);
	      
  // we will need to build the adajacency matrix first and simultaneously we will calculate
	// the indegree
			vector<vector<int>> adj(V);
	
      for(int i=0;i<preq.size();i++)
      { 
				adj[preq[i][1]].push_back(preq[i][0]);
        indeg[preq[i][0]]++;
      }
	    // find all the nodes with 0 indegree
	    for(int i=0;i<indeg.size();i++)
	    {
	        if(indeg[i]==0)
	         q.push(i);        
	    }
	    
	    while(!q.empty())
	    {
	        int v = q.front();
	        res.push_back(v);
	        q.pop();
	        for(auto x:adj[v])
	        {
	            indeg[x]--;
	            if(indeg[x]==0)
	             q.push(x);
	        }
	    }
	    if(res.size()!=V)
			  return {};
			else
				return res;
    }
};
  ```
</div>
