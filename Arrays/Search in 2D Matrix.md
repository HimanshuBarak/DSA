<h2>Search in 2D Matrix</h2>
<h3>Easy</h3><hr>
<div><p>
  
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 
</p>


[Problem Link](https://leetcode.com/problems/search-a-2d-matrix/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(n)
  
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
    bool searchMatrix(vector<vector<int>>& mt, int tar) {
        
        int n =mt.size(),m=mt[0].size();
     //assume the whole 2d matrix as a 1d sorted array
        int l=0,r=m*n-1;
        
    //to get row divide index my column no. and to get colum do %
        while(l<=r)
        {
            int mid = l+ (r-l)/2;
            
            if(mt[mid/m][mid%m]==tar)
                return true;
            if(mt[mid/m][mid%m]<tar)
                l=mid+1; //search in right half
            else
                r=mid -1;
        }
        return false;
    }
};
  ```
</div>
