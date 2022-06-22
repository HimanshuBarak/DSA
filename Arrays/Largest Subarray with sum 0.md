<h2>Largest Subarray with sum 0</h2>
<h3>Easy</h3><hr>
<div><p>
  
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 8
A[] = {15,-2,2,-8,1,7,10,23}
<strong>Output:</strong> 5
<strong>Explanation:</strong> The largest subarray with
sum 0 will be -2 2 -8 1 7.
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
class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        //  imagine the case -1 1 -1 1
        
        unordered_map<int,int> mp;
        int sum=0, ans=0;
       
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum==0)
              ans=max(ans,i+1);
            if(mp.find(sum)!=mp.end())
            {
                ans=max(ans,i-mp[sum]);
            }else
              mp[sum]=i;
        }
        
        return ans;
    }
};

  ```
</div>
