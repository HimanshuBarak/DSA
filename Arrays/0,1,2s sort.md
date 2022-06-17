<h2>Sort Color</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
 
</p>


[Problem Link](https://leetcode.com/problems/sort-colors/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [2,0,2,1,1,0]
<strong>Output:</strong> [0,0,1,1,2,2]
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
  1. In the one pass we do i-- so we again check for the value this is swaped the new value on i index
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
      //slightlyt poor
 class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                swap(nums[i],nums[j++]);
        }
        int i=j;
        j=nums.size()-1;
        while(j>=0 && nums[j]==2 ) j--;
        
        
        cout<<i;
        while(i<j)
        {
            if(nums[i]==2)
            {
              swap(nums[i],nums[j]);  
               while(nums[j]==2) j--;  
            }
                
            i++;
        }
    }
};
                   
                   //One pass solution 
                   
                    void sortColors(vector<int>& A) {
        int n = A.size();
         int j = 0, k = n-1;
    for (int i=0; i <= k; i++) {
        if (A[i] == 0)
            swap(A[i], A[j++]);
        else if (A[i] == 2)
            swap(A[i--], A[k--]);
    }
    }
  ```
</div>
