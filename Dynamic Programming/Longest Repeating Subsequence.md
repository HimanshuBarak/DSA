<h2>Longest Repeating Subsequence</h2>
<h3></h3><hr>
<div><p>
  Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.
  The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> str = "axxzxy"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
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
  1. Check the code 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
	public:
		int LongestRepeatingSubsequence(string s){
		    // Code here
		    
		    /*
		    Parent Problem is LCS 
		    Code variation => between lcs of the same string but consider a letter
		    part of subsequence only if i!=j
		    e.g 
		      s = aabcb    the ans as evident is  ab
		      now while finding lcs
		      
		      aabcb
		      aabcb    
		      here we wont consider a at 0 index because i!=j ,a at 1 is considerred same for b
		      
		      The main logic is adding i!=j we make sure that same subsequnce is not considered
		    */
		    int n = s.length();
		    string t= s;
		    
		    int dp[n+1][n+1];
		    
		    for(int i=0;i<=n;i++)
		    {
		        for(int j=0;j<=n;j++)
		        {   
		            if(i==0 || j==0)
		              {
		                  dp[i][j]=0; continue;
		              }
		            if(s[i-1]==t[j-1] && i!=j)
		              dp[i][j] = 1 + dp[i-1][j-1];
		            else
		              dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		        } 
		    }
		    
		   return dp[n][n];
		}

};
  ```
</div>
