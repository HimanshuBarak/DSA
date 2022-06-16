<h2>Set Matrix Zeroes</h2>
<h3>Medium</h3><hr>
<div><p>
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

 
</p>


[Problem Link](https://leetcode.com/problems/set-matrix-zeroes/)

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
  1. 3 steps really first find out from i=0 and j=1 if value zero set first value of row and colum zero
  2. we can not start for j=0 coz this will make mt[0][0] and which will ultimatley result in the first row being zero which is incorrect
  3. after this use or to select and set the value of each row and column
  4. run two sepearate loops for first row and column
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   //O(m+n) Space approach
  class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) {
       
        unordered_set<int> row;
        unordered_set<int> col;
        
        int m =mt.size();
        int n =mt[0].size();
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(mt[i][j]==0)
                {
                    row.insert(j); col.insert(i);
                }
            }
       
        for(auto x:row)
        {
            for(int i=0;i<m;i++)
                mt[i][x]=0;
        }
        for(auto x:col)
        {
            for(int i=0;i<n;i++)
                mt[x][i]=0;
        }      
    }
};
  
  //optimized approch
  class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) {
       
     int r =mt.size();
     int c =mt[0].size();
      
      //checking for first column
      int iscol=0;
      for(int i=0;i<r;i++)
        if(mt[i][0]==0)
          iscol=1; 
           
     for(int i=0;i<r;i++)
            for(int j=1;j<c;j++)
            {
                if(mt[i][j]==0)
                {
                    mt[i][0]=0; mt[0][j]=0; 
                }
            }
     for(int i=1;i<r;i++)
            for(int j=1;j<c;j++)
            {
                if(mt[i][0]==0 || mt[0][j]==0)
                {
                    mt[i][j]=0; 
                }
            }
     //check if first row needs to be zero also
     if(mt[0][0]==0)
     {
         for(int i=0;i<c;i++)
           mt[0][i]=0;
     }  
     //check if first col needs to be zero also
     if(iscol)
     {
         for(int i=0;i<r;i++)
           mt[i][0]=0;
     }        
    }
};
  ```
</div>
