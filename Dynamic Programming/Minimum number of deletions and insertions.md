<h2>Minimum number of deletions and insertions</h2>
<h3></h3><hr>
<div><p>
  
Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.
Note: The order of characters should be maintained.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> str1 = "heap", str2 = "pea"
<strong>Output:</strong> 3
<strong>Explanation:</strong> 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.
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
  1. n+m -2*lcs
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution{
		

	public:
	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
	    int n=s1.size(),m=s2.size();
	    int dp[n+1][m+1];
	    memset(dp,-1,sizeof(dp));
	    
	    for(int i=0;i<n+1;i++)
	    {
	        for(int j=0;j<m+1;j++)
	        {
	            if(i==0 ||j==0)
	            {
	                dp[i][j]=0; continue;
	            }
	            if(s1[i-1]==s2[j-1])
	             dp[i][j] = 1+dp[i-1][j-1];
	            else
	             dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
	        }
	    }
	    return n+m-2*dp[n][m];
	} 
};
  ```
</div>
