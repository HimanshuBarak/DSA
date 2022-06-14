<h2>Longest Consecutive Subsequence</h2>
<h3>Medium</h3><hr>
<div><p>
  Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
<pre>
For example, "ace" is a subsequence of "abcde".
</pre>
A common subsequence of two strings is a subsequence that is common to both strings.

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/0/?category[]=Dynamic%20Programming&page=1&query=category[]Dynamic%20Programmingpage1)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> text1 = "abcde", text2 = "ace" 
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest common subsequence is "ace" and its length is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text1 = "abc", text2 = "def"
     
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no such common subsequence, so the result is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(n*m)
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Refer Notes 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    
    int dp[1001][1001];
    
    int helper(string &s1,string &s2,int n,int m)
    {
        if(n==0 || m==0)
            return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
       
        if(s1[n-1]==s2[m-1]) //as both are same add to the subsequence size by +1
            return dp[n][m] = 1+ helper(s1,s2,n-1,m-1);
        else  //checks which returns max by first not considering the current letter of s1 and than of s2 whichever way  gives max value is chosen
            return dp[n][m] = max(helper(s1,s2,n,m-1),helper(s1,s2,n-1,m));
    }
    
    int longestCommonSubsequence(string s1, string s2) {
            
        memset(dp,-1,sizeof(dp));
        return helper(s1,s2,s1.length(),s2.length());
    }
};

//Bottom Up Approach
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int n=x ,m=y;
        int dp[n+1][m+1];
        memset(dp,-1,sizeof(dp));
        
        //intialization of the base condition
        for(int i=0;i<n+1;i++)
            dp[i][0]=0;
        for(int i=0;i<m+1;i++)
            dp[0][i]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
//add 1 to the result of the result with size of both string reduced by this letter        
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+ dp[i-1][j-1]; 
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        return dp[n][m];
    }
};
  ```
</div>
