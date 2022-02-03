<h2>4 Sum II</h2>
<h3>Medium</h3><hr>
<div><p>Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

  ```
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
  ```
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
     
<strong>Output:</strong> 1
<strong>Explanation:</strong>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
 

  
  <h2> Solution </h2>
  
  ``` c++ 
#define pb push_back
class Solution {
public:
    int fourSumCount(vector<int>& n1, vector<int>& n2, vector<int>& n3, vector<int>& n4) {
         
        
        unordered_map<lint,lint> umap;
        
        for(int i:n3)
        {
            for(int j:n4)
             {
                 
                 umap[i+j]++;
             }
        }
        lint count=0;
        for(int i:n1)
        {
           
             for(int j:n2)
             {
                count+= umap[0-(i+j)];
             }
        }
       return count;     
    }
};
  ```
</div>
