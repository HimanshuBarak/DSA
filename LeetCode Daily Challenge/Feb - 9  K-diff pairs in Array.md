<h2>Find K-diff pairs in Array</h2>
<h3>Medium</h3><hr>
<div><p>
  Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
```
0 <= i < j < nums.length
|nums[i] - nums[j]| == k
```
Notice that |val| denotes the absolute value of val.

 
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [3,1,4,1,5], k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,1,5,4], k = 0
     
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is one 0-diff pair in the array, (1, 1).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
  1. There are two cases one when k==0 and when k>0
  2. For k =0 we need to only count the numbers that are appearing more than once
  3. For rest we just need to calculate the a[i]-k or a[i]+k is present or not 
  4. We store it hashmap to remove the duplicates
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    char findTheDifference(string s, string t) {
        long long sum=0;
        
          for(int i=0;i<t.length();i++)
              sum+= t[i]-97;
          
          for(int i=0;i<s.length();i++)
              sum-=s[i]-97;
        
         char a=sum+97;
        
         return a;
    }
};
  ```
</div>
