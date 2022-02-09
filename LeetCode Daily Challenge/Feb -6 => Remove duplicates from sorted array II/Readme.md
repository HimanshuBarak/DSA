<h2>Remove Duplicates from sorted array II</h2>
<h3>Medium</h3><hr>
<div><p>Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>nums = [1,1,1,2,2,3]
<strong>Output:</strong> 5, nums = [1,1,2,2,3,_]
<strong>Explanation:</strong> Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,1,1,1,1,2,3,3]
     
<strong>Output:</strong> 7, nums = [0,0,1,1,2,3,3,_,_]
<strong>Explanation:</strong> Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        for(auto num:nums)
            map[num]++;
        
        int res = 0;
        if (k > 0) {
            for(auto a:map)
                if (map.find(a.first+k) != map.end()) 
                    res++;
        }
        
        else {
            for(auto a:map)
                if (a.second > 1)
                    res++;
        }
        
        return res;
    }
};
  ```
</div>
