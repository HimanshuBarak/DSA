<h2>Longest Consecutive Subsequence</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
 
</p>


[Problem Link](https://leetcode.com/problems/longest-consecutive-sequence/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [100,4,200,1,3,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
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
 
  <h2> Solution </h2>
  
  ``` c++ 
    class Solution {
public:
    
    // O(N) time and O(N) space
    int longestConsecutive(vector<int>& nums) {  
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0,cnt=0;
        for(auto x:s)
        {   
    //incase the previous digit is present end loop (avoids repeatition)
            if(s.find(x-1)!=s.end())
                continue;
            int y=x+1;cnt=1;
            while(s.find(y)!=s.end())
            {
                y++,cnt++;   
            }
           ans=max(ans,cnt);
        }
        
        return ans;
    }
};
  ```
</div>
