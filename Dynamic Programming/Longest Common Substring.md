<h2>Longest Common Substring</h2>
<h3>Medium</h3><hr>
<div><p>
  Given two strings. The task is to find the length of the longest common substring.

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> S1 = "ABCDGH", S2 = "ACDGHR"
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest common substring
is "CDGH" which has length 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> "ABC", S2 "ACB"
     
<strong>Output:</strong> 1
<strong>Explanation:</strong> The longest common substrings
are "A", "B", "C" all having length 1.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. If its equal add 1 to length if its not equal make length 0
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   //Bottom Up Approach
  class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        
        int dp[n+1][m+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n+1;i++)
         dp[i][0]=0;
         
        for(int i=0;i<m+1;i++)
         dp[0][i]=0; 
         
        int maxi=0;
        for(int i=1;i<n+1;i++)
         for(int j=1;j<m+1;j++)
         {
             if(s1[i-1]==s2[j-1])
              dp[i][j] = 1+ dp[i-1][j-1];
             else
              dp[i][j] = 0;
             maxi=max(dp[i][j],maxi); //checking for the longest one
         }
        
        return maxi;    
    }
};
  
  //Memoized approach
  int f(int i, int j,string &S1, string &S2,vector<vector<int>>&dp,int &ans)
    {
        int take=0,nottake1=0,nottake2=0;
        if(i<0||j<0)  //if length becomes zero for any of the string 
          return 0;
        if(dp[i][j]!=-1) 
          return dp[i][j];
        if(S1[i]==S2[j]) 
         take=1+f(i-1,j-1,S1,S2,dp,ans); //if equal return 1 
         //if not equal try out other combination but return 0 only
        nottake1=f(i-1,j,S1,S2,dp,ans);
        nottake2=f(i,j-1,S1,S2,dp,ans);
        ans=max(ans,take);  //to find is the given substring length is the maximum length 
        return dp[i][j]=take;
    }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=0;
         f(n-1,m-1,s1,s2,dp,ans);
         return ans;
    }

  // Tabulation Approach
  int longestCommonSubstr (string s1, string s2, int n, int m)
    {
     int dp[n+1][m+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n+1;i++)
         dp[i][0]=0;
         
        for(int i=0;i<m+1;i++)
         dp[0][i]=0; 
         
        int maxi=0;
        for(int i=1;i<n+1;i++)
         for(int j=1;j<m+1;j++)
         {
             if(s1[i-1]==s2[j-1])
              dp[i][j] = 1+ dp[i-1][j-1];
             else
              dp[i][j] = 0;
             maxi=max(dp[i][j],maxi); //checking for the longest one
         }
        
        return maxi;
 }
  ```
</div>
