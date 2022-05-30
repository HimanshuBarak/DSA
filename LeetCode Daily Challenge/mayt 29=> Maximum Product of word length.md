<h2>Maximum Product of Word Lengths</h2>
<h3>Medium</h3><hr>
<div><p> Given a string array words, return the maximum value of length(word[i]) * length(word[j])
  where the two words do not share common letters. If no such two words exist, return 0.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> words = ["abcw","baz","foo","bar","xtfn","abcdef"]
<strong>Output:</strong> 16
<strong>Explanation:</strong> The two words can be "abcw", "xtfn".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["a","ab","abc","d","cd","bcd","abcd"]
     
<strong>Output:</strong> 4
<strong>Explanation:</strong> The two words can be "ab", "cd".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
  
 
   
   [Dry run as per this approach](https://leetcode.com/problems/maximum-product-of-word-lengths/discuss/2085586/C%2B%2B-or-Short-w-2-Approaches-O(n)-Space)
  
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int ans=0;
        vector<bitset<26>> chars(n);
        
            for(int i=0;i<n;i++)
            {
                //setting the value of the word in the bitset
                for(auto ch:words[i])
                    chars[i][ch-'a']=1; 
                //comparing the results
                for(int j=0;j<i;j++)
                {   
                    if(isvalid(chars[i],chars[j]))
                        ans=max(ans,(int)(words[i].length()*words[j].length()));
                }
            }    
           return ans; 
    }
    bool isvalid(bitset<26> a,bitset<26> b)
    {
        for(int i=0;i<26;i++)
            if(a[i] && b[i])
                return false;
        return true;
    }
};
  ```
</div>
