<h2> Longest Palindromic String</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a string s, return the longest palindromic substring in s.

</p>


[Problem Link](https://leetcode.com/problems/longest-palindromic-substring/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> s = "babad"
<strong>Output:</strong> "bab"
<strong>Explanation:</strong> "aba" is also a valid answer.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "cbbd"
     
<strong>Output:</strong> "bb"
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>

  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
string longestPalindrome(string s) {
       
        /*
           the expected time complexity for this solution is O(N^2)
           Palindrome Approach

           for each letter at its center we expand to the left and right and find the longest palindromic 
           subsequence

        */ 
        int n=s.size();
        int start=0;
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            //for odd length
          
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r])
             {
                 
                 if(r-l+1 > maxlen)
                {
                 maxlen = r-l+1;
                 start=l;
                 }
                 l--,r++;
             }
             // for even length palindrome
             l=i,r=i+1;
             while(l>=0 && r<n && s[l]==s[r])
             {
                 
                 if((r-l+1)>maxlen)
                 {
                    maxlen = r-l+1;
                    start=l;
                 }
                 l--,r++;
             }
             
        }

        return s.substr(start,maxlen);
    }

//dp approach
string longestPalindrome(string s) {
       
        /*
           the dp approach revolves around the gap something
           meaning we keep on checking if a given string is palindrome with gap 1 2 3 4 5 ... between
           the first position and last position

           how do we do it O(N^2) => for that purpose we use simple dp
           if string s[i]==s[j] are equal
           lets say j-i+1 = 3
           then we check for middle element
           dp[l+1][r-1] => if this also gives true that mean the string is palindromie inside too 
           this is how we get the final answer

        */ 
        int n=s.size();
        int start = 0,len=1;
        vector<vector<int>> dp(n,vector<int>(n,0));
        //each character is equal to itself 
        for(int i=0;i<n;i++)
        dp[i][i]=1;

        //now we try to find all 2 length palndromic substring 
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                start=i;
                len=2;
            }
             
        }
        // now we check for string of the length 3
        for(int j=2;j<n;j++)
        {
            for(int i=0;i+j<n;i++)
            {
                int left =i;
                int right = i+j;
                if(dp[left+1][right-1]==1 && s[left]==s[right])
                {
                    dp[left][right]=1;
                    start=left;
                    len=j+1; // this is basically the differnece between first and last char position (length)
                }
            }

        }

        return s.substr(start,len);
  ```
</div>
