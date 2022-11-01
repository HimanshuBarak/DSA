<h2>Unique Paths</h2>
<h3>Medium</h3><hr>
<div><p>
  

 
</p>


[Problem Link](https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)

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
    

int uniquePaths(int m, int n) {
  // Write your code here. 
        vector<vector<int>> dp(m,vector<int>(n,-1));
       
        if(m==1)
            return 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=1; continue;
                }
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];  
  
  // Space Optimized Solution
  
  int uniquePaths(int m, int n) {
  // Write your code here. 
        vector<int> prev(n,1);
  
        if(m==1)
            return 1;
        for(int i=1;i<m;i++)
        {   vector<int> curr(n,1);
            for(int j=1;j<n;j++)
            {
                curr[j] = curr[j-1]+prev[j];
            }
         prev=curr;
        }
        return prev[n-1];   
  }
}
  ```
</div>
