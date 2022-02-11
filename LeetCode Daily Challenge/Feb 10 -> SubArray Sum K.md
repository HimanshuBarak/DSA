<h2>Subarray Sum K</h2>
<h3>Medium</h3><hr>
<div><p> Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p> 

      
 
<pre><strong>Input:</strong> nums = [1,2,3], k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1], k = 2
     
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
  We need to store the cummalituve sum till that point 
  and than check for 2 things <strong> this is crucial </strong> whether the cummalative sum itself 
  is equal to k 
  2nd  if there exists a x such that: cummaltive sum - x = k 
  An important test case here is [1,-1,0] or even  [0,0,0,0,0,0]
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
         
        int sum =0,cnt=0;
        unordered_map<int,int> mp;
       
        for(int i=0;i<a.size();i++)
        {
            sum+=a[i];
            if(sum==k)
                cnt++;
             if(mp.find(sum-k)!=mp.end())
                cnt+=mp[sum-k];
           
             mp[sum]++;
        }
        
        return cnt;
    }
};
  ```
</div>
