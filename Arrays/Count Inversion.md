<h2>Count Inversion</h2>
<h3>Medium</h3><hr>
<div><p>
  Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 5, arr[] = {2, 4, 1, 3, 5}
<strong>Output:</strong> 3
<strong>Explanation:</strong> The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
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
  1.  Refer Reverse Pairs
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
long long merge(long long  arr[], long long l,long long m, long long r)
    {
        long long b[r+1];
        long long inv_cnt=0;
        int i=l,j=m+1;
        int k=l;
        while(i<=m && j<=r)
        {
            if(arr[i]<=arr[j])
             b[k++]=arr[i++];
            else{
              b[k++]=arr[j++];
              inv_cnt+=m-i+1;
            }
             
        }
        //leftover in left side
        while(i<=m)
        b[k++]=arr[i++];
        while(j<=r)
          b[k++]=arr[j++];
          
        //copying back to the original array
        for(int i=l;i<=r;i++)
          arr[i]=b[i];
        
        return inv_cnt;
    }
   
    long long mergeSort(long long  arr[], long long l, long long r)
    {
        long long count=0;
         if(l<r){ 
            //divide the array into two halves
            int mid =(l+r)/2;
            count += mergeSort(arr,l,mid);
            count += mergeSort(arr,mid+1,r);
            count += merge(arr,l,mid,r); //for merging both the halves
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr,0,N-1);
    } 
  ```
</div>
