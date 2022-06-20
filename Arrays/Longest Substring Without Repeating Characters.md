<h2>Longest Substring Without Repeating Characters</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a string s, find the length of the longest substring without repeating characters.

 
</p>


[Problem Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> s = "abcabcbb"
<strong>Output:</strong> 3
 
<strong>Explanation:</strong> The answer is "abc", with the length of 3.
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
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  
  // Time o(2n) Space => O(n)
   class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        //we can use a hashmap for this the concept is beyond simple
        
        //better approach 
        unordered_set<char> st;
        int res=0,l=0,r=0;
        while(r<n)
        {
            if(st.find(s[r])!=st.end()) //found in set
            { //remove all the elements ans present before nd the last  
                // occurence of the element
                while(s[l]!=s[r])
                    st.erase(s[l++]);
                st.erase(s[l++]);
            }    
            res=max(res,r-l+1);
            st.insert(s[r++]);
        }
        return res;
    }
};
                   
                   // O(n) time approach
       int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        //we can use a hashmap for this the concept is beyond simple
        
        //better approach 
        unordered_map<char,int> mp;
        int res=0,l=0,r=0;
        while(r<n){     
          if(mp.find(s[r])!=mp.end()){
              //eg aarchabc  //sabse phele vala a update nhi krna
             l = max(l,mp[s[r]]+1); //update only if its greater than l
          }
           mp[s[r]]=r;
            res = max(res,r-l+1);
            r++;
        }
        return res;
    }            
  ```
</div>
