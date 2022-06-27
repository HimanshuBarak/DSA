<h2>Combination Sum</h2>
<h3>Medium</h3><hr>
<div><p>
  Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 
</p>


[Problem Link](https://leetcode.com/problems/combination-sum/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> candidates = [2,3,6,7], target = 7
<strong>Output:</strong> [[2,2,3],[7]]
<strong>Explanation:</strong> 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
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
    //is this similar to unbounded knapsack ,boyhs it does feeeeel similar atleast
    
    void solve(vector<vector<int>> &res,vector<int> &ans,vector<int> arr,int tar,int n){
        if(n<0)
            return;
        if(tar==0)
        {
            res.push_back(ans);
            return;
        }
        
        if(arr[n]<=tar) //is it viable
        {  //pick
            ans.push_back(arr[n]);
            solve(res,ans,arr,tar-arr[n],n);
            ans.pop_back();
            //not pick
            solve(res,ans,arr,tar,n-1);
        }else
            solve(res,ans,arr,tar,n-1);
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> ans;
        solve(res,ans,candidates,target,candidates.size()-1);
        return res;
    }
};
  ```
</div>
