<h2>Add Digits</h2>
<h3>Easy</h3><hr>
<div><p>Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> num = 38
<strong>Output:</strong> 2
<strong>Explanation:</strong> The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 0
     
<strong>Output:</strong> 0
<strong>Explanation:</strong>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
  1. Write numbers from 1 to 100
  2. calculate their modulo w.r.t 9 and you will see the pattern
  
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int addDigits(int num) {
        //write the sum of digits from 1 to 100 and see the pattern
        
        if(num==0)
            return 0;
        else if(num%9==0)
            return 9;
        else
            return num%9;
    }
};
  ```
</div>
