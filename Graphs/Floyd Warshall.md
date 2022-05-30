<h2>Floyd Warshall</h2>
<h3>Medium</h3><hr>
<div><p>
  
The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
The Graph is represented as adjancency matrix, and the matrix denotes the weight of the edegs (if it exists) else -1. Do it in-place.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1)

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
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dist){
	    // Code here
	    
	    // this is pretty simple if you think it like this
	    //for each edge we try to relax it by adding a vertex in between 
	    // bss yehi h apna college ki 6 min ke video dekh agr abb bhi yaad nhi aarha toh
	    
	    //isme -1 is given instead of nfinity so isliye thodi conditions zyada
	    int n = dist.size();
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if(dist[i][k]!=-1 && dist[k][j]!=-1) //taking care of that -1 shit
	                 {
	                   if(dist[i][j]==-1)
	                     dist[i][j] = dist[i][k] +dist[k][j];
	                   else
	                     dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
	                 }
	            }
	        }
	    }
	  
	}
};
  ```
</div>
