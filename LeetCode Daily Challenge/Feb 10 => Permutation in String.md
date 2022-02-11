<h2>Permutation in String </h2>
<h3>Medium</h3><hr>
<div><p> Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> s1 = "ab", s2 = "eidbaooo"
<strong>Output:</strong> true
<strong>Explanation:</strong> s2 contains one permutation of s1 ("ba").
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "ab", s2 = "eidboaoo"
     
<strong>Output:</strong> false
<strong>Explanation:</strong>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
  Maintain the character frequency in two vector 
  one containing the s1 character frequency 
  other containing s2 while traversing
  use sliding window for updation of s2 character frequency
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //this is quite simple actually
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        
        for(int i=0;i<s1.length();i++)
            v1[s1[i]-'a']++;
        
        int i=0,j=0;
        
        if(s2.length() <s1.length())
            return false;
        
        while(j<s2.length())
        { 
          v2[s2[j++]-'a']++;  
          if(j<s1.length())
              continue;
          if(v2==v1)
              return true;
          v2[s2[i++]-'a']--;  
           
            
        }
       return false; 
    }
};
  ```
</div>
