<h2>Shortest Palindrome</h2>
<h3>Hard</h3><hr>
<div><p>
  You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 
</p>


[Problem Link](https://leetcode.com/problems/shortest-palindrome/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> s = "aacecaaa"
<strong>Output:</strong> "aaacecaaa"
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcd"
     
<strong>Output:</strong> "dcbabcd"
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
 
  <h2> Solution </h2>
  
  ``` c++ 
     class Solution {
public:
    string shortestPalindrome(string s) {
        
        /*
             aaceaaa
        */

         string rev =s;
         reverse(rev.begin(),rev.end());
         string pat = s+"#"+rev;
         int  m = pat.size();
        vector<int> lps(m,0);

        // the first index by default remains 0 we dont consider the  whole string
        //  for a prefix and suffix

        int len=0;
        int i=1;
        while(i<m)
        {
           if(pat[i]==pat[len]) 
             { 
               len++;  
               lps[i]=len;
                i++;
             }  
            else{
               if(len==0)
               {
                  lps[i]=0;
                  i++;
               }
               /*
                  take this example to understand the algorithm
                             abcabc
                lps would be:000123    

               */
               else{
                 len = lps[len-1];
               }
            }          
        }

        // now lps stores the max length of the common prefix from begining
        // note we can only add the string in beginin
        int l = lps[m-1];
        string tmp = s.substr(l); // take all letters after the first l letters and reverse them
        reverse(tmp.begin(),tmp.end());
        return tmp+s;
      
    }
};
  ```
</div>
