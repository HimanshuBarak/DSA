<h2>Permutations of a Array,String</h2>
<h3>Medium</h3><hr>
<div><p>
  Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 
</p>


[Problem Link](https://leetcode.com/problems/permutations/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,1]
     
<strong>Output:</strong> [[0,1],[1,0]]
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
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
     // Time => O((2^n)*n) Space = > O(2n)
    class Solution {
public:
    //recursive solution at each call we fix the positoin of one and try for all other values
    void solve(vector<int> &nums,vector<vector<int>> &res, vector<int> &ans,vector<int> &freq)
    {
        if(ans.size()==nums.size())
        {
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i])
            {
                ans.push_back(nums[i]);
                freq[i]=1; //mark the index visited
                solve(nums,res,ans,freq);
                ans.pop_back();
                freq[i]=0;
            }
        }
    }
    //freq array checks if the the element at this position has been visited or not 
    // quite useful stuff if you ask me
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> freq(nums.size(),0);
        vector<vector<int>> res;
        vector<int> ans;
        
        solve(nums,res,ans,freq);
        return res;
    }
};
  // Time => O((2^n)*n) Space = > O(1)
  class Solution {
public:
    //swap and find out all the various permutations
    void solve(vector<int> &nums,vector<vector<int>> &res,int index)
    {
      if(index==nums.size())
      {
          res.push_back(nums);
          return;
      }
      for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        solve(nums,res,index+1); //here you have to do index+1 ,not i+1 run a test case nd see
        swap(nums[index],nums[i]);
        }
    }  
    vector<vector<int>> permute(vector<int>& nums) {   
        vector<vector<int>> res;
        solve(nums,res,0);
        return res;
    }
};
  ```
</div>
