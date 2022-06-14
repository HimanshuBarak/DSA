<h2>Scrambled String</h2>
<h3>Hard</h3><hr>
<div><p>
  
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
 
</p>


[Problem Link](https://leetcode.com/problems/scramble-string/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> s1 = "great", s2 = "rgeat"
<strong>Output:</strong> true
<strong>Explanation:</strong> One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
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
  1. read explanation in notebook ,its judt too much to explain here
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution {
public:
    //kya gol gol ghumane wala ques h bhai ye
    
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        
         if(s1==s2)
             return true;
          
        if(s1.length()<=1) // imagine the case s1='a' nd s2='b' since they r nt equal f
            return false;
        
        //checking if this particular entry of s1,s2 is already present in the map
        string key =s1+"$"+s2;
        int n=s1.length(); 
        if(mp.find(key)!=mp.end())
            return mp[key];
        
        bool f=false;
        // i has to start from 1 coz min length of string has to be 1
        for(int i=1;i<s1.length();i++)
        { 
            //case 1=> front is reverse(swapped with back)
             if (isScramble(s1.substr(0, i), s2.substr(0, i))
            && isScramble(s1.substr(i, n - i),
                          s2.substr(i, n - i))) {
            f = true;
            return true;
        }
 
       //
        if (isScramble(s1.substr(0, i), s2.substr(n - i, i))
            && isScramble(s1.substr(i, n - i),
                          s2.substr(0, n - i))) {
            f = true;
            return true;
        }
    
        }
            
        return mp[key]=f;    
    }
};
  ```
</div>
