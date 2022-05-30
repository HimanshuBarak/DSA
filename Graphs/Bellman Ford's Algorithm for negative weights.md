<h2>Bellman Ford Algorithm</h2>
<h3>Medium</h3><hr>
<div><p>
  
In this one we will add a step further and check if the graph contains a negative cycle or not 
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1)

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
<strong>Time:</strong> O(n*m)
  
<strong>Space:</strong> 
  
  <h2> Algorithm </h2>
 <pre>
  1. Make a distance array initialized to infinty or something
  2. Realx all the edges n-1 times
  3.  Realxing means for an edge u to v  if dist[u] +wt <dist[v] update the distance
  4. If on the nth relaxation the distance array values changes this means there is a negative weight cycle present in the graph
  </pre>
  
  
  
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
  
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    vector<int> dist(n,1000000007);
	    dist[0]=0;
	    //Relaxing the edges n-1 times
	    for(int i=0;i<n-1;i++)
	    {
	       for(auto x:edges)
    	    {
    	        if((dist[x[0]]+x[2])<dist[x[1]])
    	         {
    	             dist[x[1]] = dist[x[0]]+x[2];
    	           //  cout<<dist[x[2]]<<"--";
    	         }
    	    } 
	    }
	    
	   
	    bool f1=false;
	    for(auto x:edges)
	    {
	        if((dist[x[0]]+x[2])<dist[x[1]])
	         {
	            f1=true;
	            break;
	         }
	    }
	    
	    return f1;
	}
};
  ```
</div>
