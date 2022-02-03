<h2>Find All Anagrams in a String => Feb 2</h2>
<h3>Medium</h3><hr>
<div><p>Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>s = "cbaebabacd", p = "abc"
<strong>Output:</strong> [0,6]
<strong>Explanation:</strong> The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abab", p = "ab"
     
<strong>Output:</strong> [0,1,2]
<strong>Explanation:</strong>The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  
  <h2> Solution </h2>
  
  ``` c++ 
#define pb push_back
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> alp (26,0);
        vector<int> pv(26,0);
        if(s.length()<p.length())
            return res;
        int start=0;
        for(int i=0;i<p.length();i++)
        {
            alp[s[i]-97]++;
            pv[p[i]-97]++;
            
        }
        if(alp==pv)
            res.pb(start);
        
        
        for(int i=p.length();i<s.length();i++)
        {
            alp[s[i]-97]++;
            alp[s[start++]-97]++;
            
            if(alp==pv)
                res.pb(start);
                
        }
        
        return res;
    }
};
  ```
</div>
