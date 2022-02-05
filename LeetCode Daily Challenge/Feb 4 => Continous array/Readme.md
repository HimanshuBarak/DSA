<h2>Continours Array</h2>
<h3>Medium</h3><hr>
<div><p>Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>nums = [0,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [0,1,0] 
     
<strong>Output:</strong> 2
<strong>Explanation:</strong>[0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  
  <h2> Solution </h2>
  
  ``` c++ 
#define pb push_back
class Solution {
public:
    int findMaxLength(vector<int>& a) {
      
        unordered_map<int,int> mp;
        
        mp[0]=-1;
        int sum=0;
        int t=0,temp=0;
        for(int i=0;i<a.size();i++)
        { 
            temp=0;
            if(a[i]==0)
                t--;
            else 
                t++;
            
            if(mp.find(t)!=mp.end())
            {
                    temp=i-mp[t];
            }
            else
            mp[t]=i;
            sum=max(sum,temp);
        }
            
        return sum ;    
    }
};  
  ```
</div>
