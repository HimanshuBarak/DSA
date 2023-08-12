<h2>Sliding Window Maximum</h2>
<h3>Hard</h3><hr>
<div><p>
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
 
</p>


[Problem Link](https://leetcode.com/problems/sliding-window-maximum/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [1,3,-1,-3,5,3,6,7], k = 3
<strong>Output:</strong> [3,3,5,5,6,7]
<strong>Explanation:</strong> 
  Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1], k = 1
     
<strong>Output:</strong> [1]
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(N)
  
<strong>Space:</strong> O(N)
  <h2> Algorithm </h2>
 <pre>
  1. We will use a deque to get the ans
  2. On each insertion of a element to the window we will remove the elements which are less that current element as now since the new element
     is present they will never be the answer and this is exactly all we need to solve the problem
  3. 
  
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
       // here we will use a simple monotonic queue (deque bhai)
       
       /*

         removing the out of bounds index
         storing the ans 
         removing the redundant elements


       */
       vector<int> res;
       int n = arr.size();
       if(n==1)
        return {arr[0]};
       deque<int> dq;
          
       for(int i=0;i<n;i++)
       {
            
             // removing the last index of previous sliding window
             if(!dq.empty()&&dq.front()==i-k)
               dq.pop_front();
             
             //now deleting all the elements in current window which are smaller than our 
             // element
             while(!dq.empty() && arr[dq.back()]<arr[i])
               dq.pop_back();
             dq.push_back(i);
            if(i-k+1>=0)
             res.push_back(arr[dq.front()]);   
       }

        return res;
    }
};
  ```
</div>
