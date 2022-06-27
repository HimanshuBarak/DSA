<h2>SubSet Sum II</h2>
<h3>Medium</h3><hr>
<div><p>
  Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 
</p>


[Problem Link]()

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,2,2]
<strong>Output:</strong> [[],[1],[1,2],[1,2,2],[2],[2,2]]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0]
     
<strong>Output:</strong> [[],[0]]
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution {
public:
    //wow man this is actually a very good question
    //first of all we sort the input array (lol goes without saying)
    //we have to find all subsets of size 1 ,size 2 size 3.....size n-1
    //to avoid dupication for  a given size we don't consider the same term twice
    // and its done as sim[ple] as that
    // i!=index important bcoz we only have to consider till current index not previous cyle
    void solve(vector<vector<int>> &res, vector<int> nums,vector<int> &ans,int index)
    {
          res.push_back(ans); //add the previous digits
          for(int i=index;i<nums.size();i++)
          {
              if(i!=index && nums[i]==nums[i-1]) continue ; //dont consider duplicate items for same               
              ans.push_back(nums[i]); 
              solve(res,nums,ans,i+1); //consider the next index this is already considered
              ans.pop_back(); //backtracking step , have to clear up the array
          }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
          sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        solve(res,nums,ans,0);
        return res;
    }
};
  ```
</div>
