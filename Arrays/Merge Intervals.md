<h2>Merge Intervals</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 
 
</p>


[Problem Link](https://leetcode.com/problems/merge-intervals/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> intervals = [[1,3],[2,6],[8,10],[15,18]]
<strong>Output:</strong> [[1,6],[8,10],[15,18]]
<strong>Explanation:</strong> Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
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
  1. We have to sort as per starting (ending se krega toh inn jaise test case m problem [2,3] [4,6],[1,10])
  2. Bss rest is self explanotry
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    
    static bool comp(vector<int> a,vector<int> b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& v) {
        
        sort(v.begin(),v.end(),comp);
        vector<vector<int>> res;
        
        res.push_back(v[0]);
        
        for(int i=1;i<v.size();i++)
        {
            if(res.back()[1]>=v[i][0])
                res.back()[1] = max(res.back()[1],v[i][1]);
            else
            res.push_back(v[i]);
        }
        
        return res;
    }
};
  ```
</div>
