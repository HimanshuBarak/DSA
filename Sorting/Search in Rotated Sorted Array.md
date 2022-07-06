<h2>Search in Rotated Sorted Array</h2>
<h3>Medium</h3><hr>
<div><p>
  

 
</p>


[Problem Link]()

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 0
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 3
     
<strong>Output:</strong> -1
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
    int search(vector<int>& a, int tar) {
        
        //at any given index atleast one side is sorted w.r.t to the index we use this fact
        
        int l=0,r=a.size()-1;
        
        
        while(l<=r)
        {
            int mid =l +(r-l)/2;
            
            if(a[mid]==tar)
            {
                return mid;
            }else if(a[l]<=a[mid]){  //the left side is sorted 
                if(tar>=a[l]&&tar <a[mid])
                    r=mid-1;
                else
                    l=mid+1;
            }
            else   //teh right side is sorted
            {
                if(tar>=a[mid]&&tar <=a[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
            
        }
        
        return -1;
    }
};
  ```
</div>
