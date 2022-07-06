<h2>Median of two sorted Arrays</h2>
<h3>Medium</h3><hr>
<div><p>
 Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)). 

 
</p>


[Problem Link](https://leetcode.com/problems/median-of-two-sorted-arrays/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums1 = [1,3], nums2 = [2]
<strong>Output:</strong> 2.0000
<strong>Explanation:</strong> merged array = [1,2,3] and median is 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2], nums2 = [3,4]
     
<strong>Output:</strong> 2.5000
<strong>Explanation:</strong> merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //this needs to be done coz if we don't assume the testcase 
        // [2]
        // [0]
        //here cut2 will get value 1 which is invalid and causes error hence the reversal to get
        //the shorter of the two array
        if(nums2.size()<nums1.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int n1=nums1.size(),n2=nums2.size();        
        int low=0, high=n1;
 
        while(low<=high)
        {
            int cut1 = low + (high-low)/2;
            int cut2 = (n1+n2+1)/2 -cut1;  //this is done so that at any given moment 
            //the total item partioned are half in case of even nd half+1 in case of odd
            //have to consider the condition that no element is selected
            int left1 = cut1==0?INT_MIN:nums1[cut1-1];
            int left2 = cut2==0?INT_MIN:nums2[cut2-1];
            //the condition the whole array is considered
            int right1 = cut1==n1?INT_MAX:nums1[cut1];
            int right2 = cut2==n2?INT_MAX:nums2[cut2];
           
            if(left1<=right2 && left2<=right1)
            {
                if((n1+n2)%2==0)
                    return (max(left1,left2)+min(right1,right2))/2.0; //we take average of mid values 
                else
                    return max(left1,left2);
            }
            else if(left1>right2) //move to left
                high=cut1-1;
            else           //move to right
                low=cut1+1;
        }
        
        return 1.000;
    }
};
  ```
</div>
