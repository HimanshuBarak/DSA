<h2>Minimum Multiplications to reach End</h2>
<h3> Medium </h3><hr>
<div><p>
Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.  

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1)

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
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  #define pInt pair<int,int>

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        // here we can assume nodes from 1 to 100000
        vector<int> dist(100000,INT_MAX);
        int mod = (int)(1e5);
        priority_queue<pInt, vector<pInt>, greater<pInt>> pq; 
        
        dist[start] = 0;
        if(start==end)
          return 0;
        pq.push({0,start});
        
        while(!pq.empty())
        {
            int v = pq.top().second;
            int steps = pq.top().first;
            pq.pop();
            for(auto x:arr)
            {
              int num = v*x%mod;
              if(steps+1 < dist[num])
               {
                 dist[num] = steps+1;
                 // as we are using the minheap and selectin min steps each time we will
                 //always reach the destination with least steps in first time also
                 if(num==end)
                  return dist[num];
                 pq.push({steps+1,num}); 
               }
            }
        }
        
        return -1;
    }
};
  ```
</div>
