<h2> Prerequisite Tasks</h2>
<h3>Medium</h3><hr>
<div><p> 
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
<strong>Output:</strong> Yes
<strong>Explanation:</strong>  To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.
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
  1. Detect cycle 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    bool checkcycle(vector<int> adj[],vector<int> &vis,vector<int> &dfs_vis,int v){
        vis[v]=1;
        dfs_vis[v]=1;
        for(auto x:adj[v])
        {
            if(dfs_vis[x])
            {
               return true;
            }else if(!vis[x] &&checkcycle(adj,vis,dfs_vis,x))
                  return true;
            
        }
        dfs_vis[v]=0;
        return false;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& pr) {
	    // Code here
	    
	    vector<int> adj[N];
	    for(auto x:pr)
	    {
	        adj[x.first].push_back(x.second);
	    }
	    
	    vector<int> vis(N,0);
	    vector<int> dfs_vis(N,0);
	    
	    for(int i=0;i<N;i++)
	    {
	        if(!vis[i])
	        {
	            if(checkcycle(adj,vis,dfs_vis,i))
	              return false;
	        }
	    }
	    return true;
	}
};
  ```
</div>
