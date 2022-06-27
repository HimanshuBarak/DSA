<h2>Subset Sum</h2>
<h3>Easy</h3><hr>
<div><p>
  Given a list arr of N integers, print sums of all subsets in it

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/subset-sums2234/1#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 2
arr[] = {2, 3}
<strong>Output:</strong> 0 2 3 5 
<strong>Explanation:</strong> When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
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
  class Solution
{
public:
   //for every value we calculate two ways ,take it or not take it 
   
    void solve(vector<int> arr, vector<int> &res,int sum,int n)
    {
        if(n<0){
          res.push_back(sum);
          return;
        }
        solve(arr,res,sum+arr[n],n-1); //find all subsets with this value included 
        solve(arr,res,sum,n-1); //find all subsets without this value included
        return; 
    } 
    vector<int> subsetSums(vector<int> arr, int N)
    {
       vector<int> res;
       solve(arr,res,0,N-1);
       return res;
    }
};
  ```
</div>
