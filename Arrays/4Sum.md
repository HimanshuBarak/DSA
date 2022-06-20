<h2>4Sum</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
 
</p>


[Problem Link](https://leetcode.com/problems/4sum/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,0,-1,0,-2,2], target = 0
<strong>Output:</strong> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> n^3
  
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
    vector<vector<int>> fourSum(vector<int>& a, int k) {
        
        int n=a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> res;
        for(int i=0;i<n-3;i++)
        {  if(i>0 && a[i]==a[i-1])
             continue;  //avoiding duplicate cases and saving time
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && a[j]==a[j-1])  //avoiding duplicates
                    continue;
                int l=j+1,r=n-1;
                while(l<r)
                {
                    long x=(long)a[i]+(long)a[j]+(long)a[l]+(long)a[r];   
                    if(x<k)
                      l++;
                    else if(x>k)
                      r--;
                    else{          
                      res.push_back({a[i],a[j],a[l],a[r]});
                        l++;r--;
                      while(l<r && a[l]==a[l-1]) l++;     //this has to be inside coz if it aint unnecessary dusri side ka +/- hojaega
                      while(r>l && a[r]==a[r+1]) r--;
                    }
                       
                }
            }
        }
        
        return res;
    }
};
  ```
</div>
