<h2>Flood Fill</h2>
<h3>Easy </h3><hr>
<div><p>
  
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.
 
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
<strong>Output:</strong> [[2,2,2],[2,2,0],[2,0,1]]
<strong>Explanation:</strong> From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
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
  1. Simple BFS
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
#define f first
#define s second
class Solution {
public:
    
    bool isvalid(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int nc) {
        
        
        int m =img.size();
        int n = img[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
         
        int dx [] = {1,-1,0,0};
        int dy [] = {0,0,1,-1};
        int c =img[sr][sc];
        vis[sr][sc]=1;
        q.push({sr,sc});
        
        while(!q.empty())
        {
            pair<int,int> p =q.front();
            q.pop();
            int x = p.f; int y=p.s;
            img[x][y]=nc;
            for(int i=0;i<4;i++)
            {
                if(isvalid(x+dx[i],y+dy[i],m,n) && !vis[x+dx[i]][y+dy[i]] && img[x+dx[i]][y+dy[i]]==c)   
                   {
                       vis[x+dx[i]][y+dy[i]]=1;
                       q.push({x+dx[i],y+dy[i]});
                   }        
             }
        }
                   return img;
    }
};
  ```
</div>
