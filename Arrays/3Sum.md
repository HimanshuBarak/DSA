<h2>3Sum</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
 
</p>


[Problem Link](https://leetcode.com/problems/3sum/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [-1,0,1,2,-1,-4]
<strong>Output:</strong> [[-1,-1,2],[-1,0,1]]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> []
     
<strong>Output:</strong> []
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {   
            if(i!=0 &&nums[i]==nums[i-1])
                continue;
            int l=i+1,r=n-1;
            while(l<r)
            {
                int x = nums[i]+nums[l]+nums[r];
                
                if(x<0)
                    l++;
                else if(x>0)
                    r--;
                else {
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;r--;
                    //to avoid duplicates
                    while(l<r && nums[l]==nums[l-1])l++;
                    while(r>l &&nums[r]==nums[r+1])r--;
                }
                    
            }
        }
        return res;
    }
};
  ```
</div>
