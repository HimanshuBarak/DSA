<h2>Boyre Moore</h2>
<h3>Easy</h3><hr>
<div><p>
  
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 
</p>


[Problem Link](https://leetcode.com/problems/majority-element/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [2,2,1,1,1,2,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Intuitive
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //we will use the boyer moore vala thing
        
        int ans=nums[0],cnt=1;  
        for(int i=1;i<nums.size();i++)
        {   
            if(cnt==0)
            {
                ans=nums[i]; cnt++;
            }
            else if(nums[i]==ans) 
                cnt++;
            else 
                cnt--;
        }
        return ans;
    }
};
  ```
</div>
