<h2>Excel Sheet Column Number</h2>
<h3>Easy</h3><hr>
<div><p> Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:
  <pre>
  A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
  </pre>
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p> 

      
 
<pre><strong>Input:</strong> columnTitle = "AB"
<strong>Output:</strong> 28
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> columnTitle = "ZY"
     
<strong>Output:</strong> 701
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>


  <h2> Algorithm </h2>
   somewhat similar to converting bianry to decimal here 26 instead of 2.
 
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int titleToNumber(string s) {
       
        long long sum=s[0]-64;
        
        for(int i=1;i<s.length();i++)
        {              
            sum=sum*26+ (s[i]-64);    
        }
        
        return sum;
    }
};
  ```
</div>
