<h2>Numbers With Same Consecutive Differences</h2>
<h3>Medium</h3><hr>
<div><p>
  Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

 
</p>


[Problem Link]()

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>  n = 3, k = 7
<strong>Output:</strong> [181,292,707,818,929]
<strong>Explanation:</strong> Note that 070 is not a valid number, because it has leading zeroes.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, k = 1
     
<strong>Output:</strong> 
<strong>Explanation:</strong> [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(2^N)
  
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
    class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        
        for(int i=2;i<=n;i++)
        {
            vector<int> temp; //stores all valid number with i+1 digits
            for(auto x:nums)
            {
                int y = x%10; //getting the last digit   
                if((y+k)<10)
                    temp.push_back(x*10+y+k);
                 if(k>0 && (y-k)>=0)
                   temp.push_back(x*10+y-k); 
            }
            //update the valid number containin i digits
            nums=temp;
        }
        return nums;
    }
};

  ```
</div>
