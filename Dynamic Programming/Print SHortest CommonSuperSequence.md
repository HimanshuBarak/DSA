<h2>Print Shortest Common Supersequence</h2>
<h3>Hard</h3><hr>
<div><p>
  Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 
</p>


[Problem Link](https://leetcode.com/problems/shortest-common-supersequence/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> str1 = "abac", str2 = "cab"
<strong>Output:</strong> "cabac"
<strong>Explanation:</strong> str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
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
  1. Find lcs and create the dp matrix
  2. Printing the string is the crux here
  3. While printing lcs also print the letter which are not equal
  4. if (i-1 vala is greater than j-1) add letter of s1 else of s2
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.length() ,m=s2.length();
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
        // int len = n+m-dp[n][m] =>length of shortest supersequence
        int i=n,j=m;
        
        string ans="";
       //printing the string
        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                ans+=s1[i-1];
                i--;j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1])
                {
                    ans+=s1[i-1];
                    i--;
                }else{
                    ans+=s2[j-1];
                    j--;
                }
            }
                
        }
        while(i>0){
            ans+=s1[i-1];i--;
        }
            
        while(j>0){
            ans+=s2[j-1]; j--;
        }
            
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
  ```
</div>
