<h2>Next Permutation</h2>
<h3>Medium</h3><hr>
<div><p>
  A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 
</p>


[Problem Link](https://leetcode.com/problems/next-permutation/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,3,2]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,1]
     
<strong>Output:</strong> [1,2,3]
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Given in the code
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    
   
    void nextPermutation(vector<int>& nums) {
        
       int n = nums.size()-1;
    int i=n;
    int start=0,end=n; //index for which to start sorting
    //finding the break point
    while(i>0)
    {
        if(nums[i]>nums[i-1])
        {
            //finding next greatest element to replace
            int j=n;
            while(nums[j]<=nums[i-1])j--;
            swap(nums[i-1],nums[j]);
            start = i; //ise aage ka ascending order m sort kardo tabhi next greatest mileaga
            break;
        }
        i--;
    }
    
    //sorting 
        cout<<start<<"--"<<end;
    while(start<end)
    {
        swap(nums[start],nums[end]); start++,end--;
    }
   
    }
};
  ```
</div>
