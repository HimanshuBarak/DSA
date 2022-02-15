<h2>Single Number</h2>
<h3>Easy</h3><hr>
<div><p> Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p> 

      
 
<pre><strong>Input:</strong> nums = [2,2,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 1 appears only once 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>
     
<strong>Output:</strong> nums = [4,1,2,1,2]
<strong>Explanation:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>


  <h2> Algorithm </h2>
 [Aprroach](https://leetcode.com/problems/single-number/discuss/1771816/C%2B%2B-O(n)-solution-using-XOR-beginners-explanation)
 
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int singleNumber(vector<int>& a) {
        
        int ans=a[0];
        
        for(int i=1;i<a.size();i++)
            ans^=a[i];
        
        
        return ans;
    }
};
  ```
</div>
