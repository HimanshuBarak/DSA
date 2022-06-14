<h2>Longest Palindromic Subsequence</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
 
</p>


[Problem Link](https://leetcode.com/problems/longest-palindromic-subsequence/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> s = "bbbab"
<strong>Output:</strong> 4
<strong>Explanation:</strong> One possible longest palindromic subsequence is "bbbb"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "cbbd"
     
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Find lcs of the string with its reverse
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        string t ="";
        for(int i=n-1;i>=0;i--)
            t+=s[i];
        
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0; continue;
                }
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }
};
  ```
</div>
