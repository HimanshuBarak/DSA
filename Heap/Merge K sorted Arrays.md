<h2>Merge K sorted Arrays</h2>
<h3>Medium</h3><hr>
<div><p>
  Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
 
</p>


[Problem Link]()

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
<strong>Output:</strong> 1 2 3 4 5 6 7 8 9
<strong>Explanation:</strong> Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].
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
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   typedef pair<int,int> pi;
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //navie approach time => O(N*K)log(N*K)
        /*
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                pq.push(arr[i][j]);
            }
        }
        
        vector<int> res;
        
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        */
        // efficient approach  time O(N*Klog(K)
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<int> idx(arr.size(),0); //this store the ongoing index of each array in the posn array no
        vector<int> res;
        //we push the first element of all the matrices
        
        int n = arr[0].size(); //length of all the arrays is same 
        for(int i=0;i<n;i++)
          pq.push({arr[i][0],i});
         
        
        while(!pq.empty()){
            pi t = pq.top();
            res.push_back(t.first); //storing the min value
            idx[t.second]++; //increase the index of array whose element is added in res
            pq.pop();
            //if this array is yet to be traversed completely add the next element
            if(idx[t.second]<n) 
              pq.push({arr[t.second][idx[t.second]],t.second});
        }
        return res;
    }
};
  ```
</div>
