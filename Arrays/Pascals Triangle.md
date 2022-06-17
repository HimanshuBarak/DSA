<h2>Pascals Triangle</h2>
<h3>Easy</h3><hr>
<div><p>
  
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 
</p>


[Problem Link](https://leetcode.com/problems/pascals-triangle/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> n=5
<strong>Output:</strong> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
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
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
    class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> res;
        int level=1;
  //ech level has the same no of elements as the level value with the first and alst element being 1 
  //rest take from upper one
        while(level<=n)
        {    vector<int> temp(level,1);
            for(int i=1;i<level-1;i++)
            {  
                temp[i] = res[level-2][i]+res[level-2][i-1];
            }
         res.push_back(temp); level++;
         
        }
        return res;
    }
};
  ```
</div>
