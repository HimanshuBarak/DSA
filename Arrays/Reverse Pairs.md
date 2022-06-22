<h2>Reverse Pairs</h2>
<h3>Hard</h3><hr>
<div><p>
  Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 
</p>


[Problem Link](https://leetcode.com/problems/reverse-pairs/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,3,2,3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,4,3,5,1]
     
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution {
public:
    /* 
The main idea is to use Merge Sort. In merge sort when we find a[i]>a[j]
we add mid-i+1 (+1 for the current) mid-i coz all element till mid are sorted and greater than the current one so if current element is greater so will be they
    */
    //the most important function of the algorithm
    int merge(vector<int>& arr,int l,int m,int r)
    {
        int b[r+1];
        int i=l,j=m+1;
        int cnt=0;
        while(i<=m && j<=r)
        {
            if((long)arr[i]>(long)2*arr[j])
            {
                cnt+=(m-i+1); //Check problem inversion of array
                j++;
            }else
                i++;
        }
        //sorting the array
        i=l,j=m+1;
        int k=l;
        
        while(i<=m && j<=r)
        {
            if(arr[i]<=arr[j])
                b[k++]=arr[i++];
            else
               b[k++]=arr[j++]; 
        }
        while(i<=m)
        {
          b[k++]=arr[i++];  
        }
         while(j<=r)
          b[k++]=arr[j++];
          
        //copying back to the original array
        for(int i=l;i<=r;i++)
          arr[i]=b[i];
        
        return cnt;
    }
    int mergeSort(vector<int>& arr,int l,int r)
    {
        int count=0;
        //standard mergeSort
        if(l<r)
        {   
            int mid = (l+r)/2;
            count+=mergeSort(arr,l,mid);
            count+=mergeSort(arr,mid+1,r);
            count+= merge(arr,l,mid,r);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums,0,nums.size()-1);
    }
};
  ```
</div>
