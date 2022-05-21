<h2>Rat in a Maze Problem</h2>
<h3>Medium</h3><hr>
<div><p> Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
<strong>Output:</strong> DDRDRR DRDDRR
<strong>Explanation:</strong> The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
<strong>Output:</strong> 
<strong>Explanation:</strong>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
  Do exhaustive dfs and explore all possibilites
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution{
    public:
    void getPath(int i,int j,vector<vector<int>> &m,vector<vector<int>> &vis,int n,vector<string> &res,string path)
    {
        if(i==n-1 && j==n-1){
            res.push_back(path);
            return;
        }
        //moving DOWN
        if(i!=n-1 && m[i+1][j]==1 &&vis[i+1][j]==0)
         {
             vis[i][j]=1;
             getPath(i+1,j,m,vis,n,res,path+"D");
             vis[i][j]=0;
         }
        
         //moving left
         if(j!=0 && m[i][j-1]==1 &&vis[i][j-1]==0)
         {
             vis[i][j]=1;
             getPath(i,j-1,m,vis,n,res,path+"L");
             vis[i][j]=0;
         }
         //moving right
        if(j!=n-1 && m[i][j+1]==1 &&vis[i][j+1]==0)
         {
             vis[i][j]=1;
             getPath(i,j+1,m,vis,n,res,path+"R");
             vis[i][j]=0;
         }
        //moving up
        if(i!=0 && m[i-1][j]==1 &&vis[i-1][j]==0)
         {
             vis[i][j]=1;
             getPath(i-1,j,m,vis,n,res,path+"U");
             vis[i][j]=0;
         } 
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string path="";
        vector<string> res;
        if(m[0][0]==0 || m[n-1][n-1]==0)
          return res;
        vector<vector<int>> vis;
        for(int i=0;i<n;i++)
        {   vector<int> row(n,0);
            vis.push_back(row);
        }
        getPath(0,0,m,vis,n,res,path);
        return res;
    }
};

  ```
</div>
