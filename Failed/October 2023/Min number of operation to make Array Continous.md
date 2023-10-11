<h2>Minimum No. of Operations to make Array Continous</h2>
<h3>Hard</h3><hr>
<div><p>
  You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

 
</p>


[Problem Link](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/?envType=daily-question&envId=2023-10-10)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [4,2,5,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,5,6]
     
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
   Need to find the longest subarray that is continous . You subtract this from n and you have your answer
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution {
public:
    int minOperations(vector<int>& nums) {
        
       // first we sort the array
       sort(nums.begin(),nums.end());
       int n = nums.size();
       // removing duplicates
       // this basically shifts all the duplicates in the end and return the index from where the duplicates are present
       auto newEnd = unique(nums.begin(),nums.end());
       nums.erase(newEnd,nums.end());

       int m = nums.size();
       
       // now we are basically trying to find the biggest subarray that is
       // continous the ans will we n - length of the largest continous subarray 
       int ans=1e9;
       for(int i=0,j=0;i<m;i++)
       {  
           
           while(j<m && nums[j]<nums[i]+n)
           j++;
           // j is always 1 greater then where the subarray ends 
           ans=min(ans,n-(j-i));
       }

       return ans;
    }
};
  ```
</div>
