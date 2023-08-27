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
  ```
</div>
