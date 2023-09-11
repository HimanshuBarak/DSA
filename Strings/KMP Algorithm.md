<h2>KMP Alogrithm</h2>
<h3>Hard</h3><hr>
<div><p>
  
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 
</p>


[Problem Link](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> haystack = "sadbutsad", needle = "sad"
<strong>Output:</strong> 0
<strong>Explanation:</strong> "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> haystack = "leetcode", needle = "leeto"
     
<strong>Output:</strong> -1
<strong>Explanation:</strong> "leeto" did not occur in "leetcode", so we return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> o(M+N)
  
<strong>Space:</strong> O(M)
  <h2> Algorithm </h2>
 <pre>
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int strStr(string txt, string pat) {
        
        if(pat=="")
          return 0;
        //we shall use KMP and make things super hard for ourself yeaaaa!!


        // 2 majors components in KMP 

        /*
          1st is to create the longest prefix suffix array(lps) array

          the purpose of this array is to avoid repaeated comparison

          take for example =>  abcabkabc
             pattern abcabc
            
            k!=c iss case we would usually set ur j to 0 
            but we know ki in the pattern we have already have ab so we move back there
            and start comparing from there

            once this is done

            we match our patttern to the text string 
            if some character doesnt match we move j to lps[i-1] position
            if j becomes zer oand still doesn't match we increment i

        */
        int n = txt.size(), m = pat.size();
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
   i=0;
   int j=0;

   while(i<n)
   {
       if(txt[i]==pat[j])
       {
          i++;
          j++;
       }else if(j==0)
         i++;
       else{
          j= lps[j-1];
       }  
       if(j==m)
         return i-m;
   }


   return -1;
    }
};
  ```
</div>
