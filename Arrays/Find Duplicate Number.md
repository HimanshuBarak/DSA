<h2>Find Duplicate Number</h2>
<h3>Medium</h3><hr>
<div><p>
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

 
</p>


[Problem Link](https://leetcode.com/problems/find-the-duplicate-number/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,3,4,2,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,3,4,2]
     
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. That rabbit tortoise thing using fast and slow pointer (very similar to find cycle starting point in linked list)
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow=nums[0],fast=nums[0];
        //finding out thr first collision
        do{
            slow = nums[nums[slow]];
            fast = nums[nums[nums[fast]]];
        }while(slow!=fast);
        
            //2nd collision
            fast=nums[0];
        
        while(slow!=fast)
        {
            slow=nums[slow];
            fast = nums[fast];
        }
           
        
        return slow;
    }
};
  ```
</div>
