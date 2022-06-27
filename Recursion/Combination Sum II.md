<h2>Combination Sum II</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

 
</p>


[Problem Link](https://leetcode.com/problems/combination-sum-ii/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> candidates = [10,1,2,7,6,1,5], target = 8
<strong>Output:</strong> [
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
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
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    //very similar to subset sum II problem
    void solve(vector<vector<int>> &res,vector<int> &ans,vector<int> arr,int tar,int index){
        if(tar==0)
        {
            res.push_back(ans);
            return;
        }
        
        for(int i=index;i<arr.size();i++)
        {   
            if(i!=index &&arr[i]==arr[i-1]) 
                continue;
        //as the array is stored if current values gives greater sum than isse age wale bhi denge
            if(arr[i]<=tar)
            {
                ans.push_back(arr[i]);
                solve(res,ans,arr,tar-arr[i],i+1);
                ans.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(cand.begin(),cand.end());
        solve(res,ans,cand,target,0);
        return res;
    }
};
  ```
</div>
