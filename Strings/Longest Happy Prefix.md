<h2>Longest Happy Prefix</h2>
<h3>Medium</h3><hr>
<div><p>
  A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
</p>


[Problem Link](https://leetcode.com/problems/longest-happy-prefix/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> s = "level" 
<strong>Output:</strong> l
<strong>Explanation:</strong> s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "ababab"
<strong>Output:</strong>  "abab"
<strong>Explanation:</strong> "abab" is the largest prefix which is also suffix. They can overlap in the original string.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(N)
  
<strong>Space:</strong> 

  <h2> Solution </h2>
  
  ``` c++ 
   class Solution {
public:
    string longestPrefix(string s) {
        // we just find the lps array and return the max value
        
        int n =s.length();
        vector<int> lps(n,0);
        int len=0,i=1;
        int ans=0;
        while(i<n)
        {
            if(s[i]==s[len])
            {
                lps[i]=++len;
                i++;
                if(i==n)
                ans=max(ans,len);
                
            }else if(len!=0)
             len = lps[len-1];
            else
             {
                 lps[i]=0;
                 i++;
             } 
        }

        return ans==0?"":s.substr(0,ans);
    }
};
  ```
</div>
