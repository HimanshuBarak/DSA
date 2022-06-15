<h2>Palindromic Partitioning</h2>
<h3>Hard</h3><hr>
<div><p>
  
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome.
  Determine the fewest cuts needed for palindrome partitioning of the given string.
 
</p>


[Problem Link](https://leetcode.com/problems/palindrome-partitioning-ii/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> s = "aab"
<strong>Output:</strong> 1
<strong>Explanation:</strong> The palindrome partitioning ["aa","b"] could be produced using 1 cut.
</pre>

<p><strong>Example 2:</strong></p> 

<pre><strong>Input:</strong> str = "ababbbabbababa"
     
<strong>Output:</strong> 3
<strong>Explanation:</strong> After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
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
     //unoptimized code
  class Solution{
public:
    int dp[500+1][500+1];
    int pal[500+1][500+1];
    int  isPalindrome(string &s,int i,int j)
    {   
        if (i >= j) return true;
        if(pal[i][j]!=-1)
            return pal[i][j];
        while(i<j)
        {
            if(s[i]!=s[j])
                return pal[i][j]=0;
            
            i++;j--;
        }
        return pal[i][j]=1;
    }
    int solve(string &s, int i, int j)
    {
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans =INT_MAX;
        //check if the string is palindrome no partition required
        if(isPalindrome(s,i,j))
            return 0;
        for(int k=i;k<=j-1;k++)
        { 
           /* 
            If loop is entered its not palindrome hence we add 1 + partiiton on lgeft + right like below
            int temp = 1+ solve(s,i,k)+solve(s,k+1,j);
            
            */
            //further optimizing the above code
           int left = dp[i][k]!=-1?dp[i][k]:solve(s,i,k);
           int right = dp[k+1][j]!=-1?dp[k+1][j]:solve(s,k+1,j); 
            ans=min(left+right+1,ans);
        }
        
        return dp[i][j] =ans;
    }
    int palindromicPartition(string s)
    {
        // code here
        
         memset(dp,-1,sizeof(dp));
         memset(pal,-1,sizeof(pal));
        return solve(s,0,s.size()-1);
    }
};
                               // optimized approach "try running it for input "abcd" and you will see what I mean
          class Solution {
public:
    int dp[2000+1][2000+1];
    int pal[2000+1][2000+1];
    int  isPalindrome(string &s,int i,int j)
    {   
        if (i >= j) return true;
        if(pal[i][j]!=-1)
            return pal[i][j];
        while(i<j)
        {
            if(s[i]!=s[j])
                return pal[i][j]=0; 
            i++;j--;
        }
        return pal[i][j]=1;
    }
    
    int solve(string &s, int i, int j)
    {
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans =INT_MAX;
        //check if the string is palindrome no partition required
        if(isPalindrome(s,i,j))
            return 0;
        for(int k=i;k<=j-1;k++)
        { 
           /* 
            If loop is entered its not palindrome hence we add 1 + partiiton on lgeft + right like below
            int temp = 1+ solve(s,i,k)+solve(s,k+1,j);
            
            */
            //further optimizing the above code
           if(isPalindrome(s,i,k))
           ans=min(solve(s,k+1,j)+1,ans);
        }
        //max cuts can be n-1 the first iteration actually takes care of that
        //thus after that we only consider strings that are palindrome 
        return dp[i][j] =ans;
    }
    int minCut(string s) { 
        memset(dp,-1,sizeof(dp));
        memset(pal,-1,sizeof(pal));
        return solve(s,0,s.size()-1);
    }
};
  ```
</div>
