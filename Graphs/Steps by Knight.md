<h2>  Steps by Knight</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

 
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p> 

      
 
<pre><strong>Input:</strong> N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
<strong>Output:</strong> 3
<strong>Explanation:</strong> Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(V+E)
  
<strong>Space:</strong> O(V)
  <h2> Algorithm </h2>
 <pre>
  1. Determine conditions for valid value of coordinates
  2. Make an array to traverse through steps from each coordinate
  3. Perform simple bfs
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution 
{
    public:
    //to check if the coordinates are actual valid coordinates
    bool isvalid(int i,int j,int n)
    {
        if(i>=1 && i<=n && j>=1 && j<=n)
          return true;
        else
          return false;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KPos,vector<int>&TPos,int n)
	{
	    // when to use BFS and When to use Dfs
	    queue<pair<int,int>> q;
	     vector<vector<int>> vis(n+1,vector<int>(n+1,0));
	     int dx [] ={-1,-1,-2,-2,1,1,2,2};
	     int dy [] ={2,-2,1,-1,-2,2,-1,1} ;
	    //if the starting posn is the target posn than no moves are required
	    
	     int tx=TPos[0],ty=TPos[1]; 
	      q.push({KPos[0],KPos[1]});
	      int count=0;
	      int ans=INT_MAX;
	      while(!q.empty())
	      {  
	          //cout<<"aaaa";
	          int size =q.size();
	          while(size--)
	          {
    	          pair<int,int> cd = q.front();
    	          q.pop();
    	          int x =cd.first;
    	          int y =cd.second;
    	         // cout<<x<<"-->"<<y<<endl;
    	          if(x==tx && y==ty)
    	            return count;
    	            
    	          for(int i=0;i<8;i++)
    	          {
    	              if(isvalid(x+dx[i],y+dy[i],n) && vis[x+dx[i]][y+dy[i]]==0)
    	               {
    	                   q.push({x+dx[i],y+dy[i]});
    	                   vis[x+dx[i]][y+dy[i]]=1;
    	               }
    	          } 
    	          
	          } 
	          count++;
    	   }
	 
	     return ans;
	}
};
  ```
</div>
