<h2>Subarray with Given XOR</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.
 
</p>


[Problem Link](https://www.interviewbit.com/problems/subarray-with-given-xor/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> A = [4, 2, 2, 6, 4]
 B = 6
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> A = [5, 6, 7, 8, 9]
 B = 5
     
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
 
  <h2> Solution </h2>
  
  ``` c++ 
   int Solution::solve(vector<int> &A, int B) {
    /*
    let us use the formaula 
     XR = Y^B
     also can be written as XR = Y^B 
     if such y exists in map that means therse exists a subarrys which gives B 
     the no. of subarrays will be the frequency of no. of times y has occured
    */
    // unordered_map has worst case O(n) whereas map has o(logn)
    map<int,int> mp;
    int xr=0,cnt=0;
    
    for(int i=0;i<A.size();i++)
    {
        xr=xr^A[i];
        if(xr==B)
         cnt++;
        if(mp.find(xr^B)!=mp.end())
        cnt+=mp[xr^B];
        
        mp[xr]++; 
    }
    
    return cnt;
}

  ```
</div>
