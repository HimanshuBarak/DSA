<h2>M-coloring Problem</h2>
<h3>Medium</h3><hr>
<div><p>  
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color.
Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
<strong>Output:</strong> 1
<strong>Explanation:</strong> It is possible to colour the
given graph using 3 colours.
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
  1. We use DFS and backtracking to try out all the possible combinations
  2. If any combination works we return true;
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
bool isSafe(int v,int n,bool graph[101][101],vector<int> col,int c){
   for(int i=0;i<n;i++)
    {
        if(i!=v && graph[i][v]==1 &&col[i]==c)
         return false;
    }
    return true;
}
bool dfs(int v,vector<int> &col,bool graph[101][101],int n ,int m){
    if(v==n)
      return true; //all vertexs are successfully colored
      
    for(int i=0;i<m;i++)
    {
        if(isSafe(v,n,graph,col,i))
        {
            col[v]=i;
            if(dfs(v+1,col,graph,n,m))
             return true;
            col[v]=-1;  //backtracking step 
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> col(n,-1);
    
    if(dfs(0,col,graph,n,m))
      return true;
    return false;  
    
}
  ```
</div>
