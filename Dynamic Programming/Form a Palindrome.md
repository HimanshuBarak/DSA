<h2>Form a Palindrome</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

 
</p>


[Problem Link]()

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> str = "abcd"
<strong>Output:</strong> 3
<strong>Explanation:</strong> Inserted character marked with bold characters in dcbabcd
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
  1. n- lcs
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution{
  public:
    int countMin(string s){
        /* Parent problem LCS
          Similiar problem min no of deletion to make string palindrom
        */  
        int n =s.length();
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
        
        return n-dp[n][n];
    }
};
  ```
</div>
