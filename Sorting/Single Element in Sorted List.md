<h2>Single Element in Sorted List</h2>
<h3>Medium</h3><hr>
<div><p>
  You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 
</p>


[Problem Link](https://leetcode.com/problems/single-element-in-a-sorted-array/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,3,7,7,10,11,11]
     
<strong>Output:</strong> 10
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
    int singleNonDuplicate(vector<int>& arr) {
        
        //we use the index to decide which side to move the search pointer
        //index start from 0 1 2 3
        //so until the single element is reached all the other elements first occurence is 
        // in even index and second on odd index; use this
        if(arr.size()==1)
            return arr[0];
        
        int l=0,r=arr.size()-1;
        
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            
            if(mid%2==0 && arr[mid]!=arr[mid+1]) //single element is towards left
                r=mid-1;
            else if(mid%2==1 && arr[mid]!=arr[mid-1]) //single element is towards left
                r=mid-1;
            else
                l=mid+1; //no anomly detected in patter so its on the right side 
        }
        return arr[l];
    }
};
  ```
</div>
