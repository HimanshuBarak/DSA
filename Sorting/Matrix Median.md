<h2>Matrix median</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.
 
</p>


[Problem Link](https://www.interviewbit.com/problems/matrix-median/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>   A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
<strong>Output:</strong> 5
<strong>Explanation:</strong>  A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

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
    int Solution::findMedian(vector<vector<int> > &mt) {
      int r =mt.size();
      int c= mt[0].size();
      int mini= mt[0][0],maxi=mt[0][0];
       
       for(int i=0;i<r;i++)
       {
           mini = min(mini,mt[i][0]);
           maxi = max(maxi,mt[i][c-1]);
       }
       int low=mini,high=maxi,res=0;
       //for a elemn to be median half the element should be grater half of them lesser
       int desired = (r*c+1)/2; //this anhy elements should be greater and lesser
       while(low<=high)
       {
           int mid = low+ (high-low)/2;
          // cout<<mid<<endl;
           int count=0;
           // r*log(c) => time complexity of below step
           for(int i=0;i<r;i++)
           { //gives no. of elements lesser than mid in the given row
               count+=upper_bound(mt[i].begin(),mt[i].end(),mid)-mt[i].begin(); 
           }
           if(count<desired)
             low=mid+1;
        else{ //for count<= desired we do this
            res=mid;
            high=mid-1; //this line is very important make sure you pay attention to it
        }
           
       }
       
       return res;
}
int Solution::findMedian(vector<vector<int> > &mt) {
      int r =mt.size();
      int c= mt[0].size();
      int mini= mt[0][0],maxi=mt[0][0];
       
       for(int i=0;i<r;i++)
       {
           mini = min(mini,mt[i][0]);
           maxi = max(maxi,mt[i][c-1]);
       }
       int low=mini,high=maxi,res=0;
       //for a elemn to be median half the element should be grater half of them lesser
       int desired = (r*c+1)/2; //this anhy elements should be greater and lesser
       while(low<=high)
       {
           int mid = low+ (high-low)/2;
          // cout<<mid<<endl;
           int count=0;
           // r*log(c) => time complexity of below step
           for(int i=0;i<r;i++)
           { //gives no. of elements lesser than mid in the given row
               count+=upper_bound(mt[i].begin(),mt[i].end(),mid)-mt[i].begin(); 
           }
           if(count<desired)
             low=mid+1;
        else{ //for count<= desired we do this
            res=mid;
            high=mid-1; //this line is very important make sure you pay attention to it
        }
           
       }
       
       return res;
}

  ```
</div>
