<h2>Subsets</h2>
<h3>Medium</h3><hr>
<div><p> Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p> 

      
 
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>
     
<strong>Output:</strong> nums = [0]
<strong>Explanation:</strong> [[],[0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>


  <h2> Algorithm </h2>
   We need to write all the permutations of possible subsets
 
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        ans.push_back({});
        
        for(int i=0; i<n; i++)
        {
            int sz = ans.size();
            for(int j=0; j<sz; j++)
            {
                vector<int> temp = ans[j];  //intialized as an empty array for j=0
               
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
  ```
</div>
