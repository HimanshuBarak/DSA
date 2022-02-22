<h2>Remove K digits</h2>
<h3>Medium</h3><hr>
<div><p> Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p> 

      
 
<pre><strong>Input:</strong> num = "1432219", k = 3
<strong>Output:</strong> "1219"
<strong>Explanation:</strong> Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "10200", k = 1
     
<strong>Output:</strong> "200"
<strong>Explanation:</strong> Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>


  <h2> Algorithm </h2>
   [https://leetcode.com/problems/remove-k-digits/discuss/607570/C%2B%2B-solution-8ms-with-detailed-explanation](https://leetcode.com/problems/remove-k-digits/discuss/607570/C%2B%2B-solution-8ms-with-detailed-explanation)
 
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    string removeKdigits(string s, int k) {
       
        string res="";
        
        
        for(int i=0;i<s.size();i++)
        {
            while(res.size() && res.back()>s[i]&&k)
            {
                res.pop_back(); k--;
            }
            
            if(res.size() || s[i]!='0')
            {
                 res.push_back(s[i]);
            }
               
        }
        // imagine a case 31117 with k=3 for such cases we need this 
        while(res.size() &&k)
        {
             res.pop_back(); k--;
        }
        
        return (res=="")?"0":res;
    }
};
  ```
</div>
