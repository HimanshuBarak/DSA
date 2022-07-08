<h2>Top K frequent Elements</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 
</p>


[Problem Link](https://leetcode.com/problems/top-k-frequent-elements/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,1,1,2,2,3], k = 2
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1], k = 1
     
<strong>Output:</strong> [1] 
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto x:mp)
        {
            pq.push({x.second,x.first});
        }
        
        for(int i=0;i<k;i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
            
        return res;    
    }
};
  ```
</div>
