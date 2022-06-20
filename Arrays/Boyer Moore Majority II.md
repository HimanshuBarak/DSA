<h2>N/3 Times occurence</h2>
<h3>Medium</h3><hr>
<div><p>
  You're given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

 
</p>


[Problem Link](https://www.interviewbit.com/problems/n3-repeat-number/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> [1 2 3 1 1]
<strong>Output:</strong> 1
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
  
  <h2> Solution </h2>
  
  ``` c++ 
int Solution::repeatedNumber(const vector<int> &a) {
    
    //the basic logic being there can not be more than 2 elements which occur more than n/3 times
    
    //so know we check for the these two elements only 
    
    int e1=-1,e2=-1,c1=0,c2=0;
    int n=a.size();
    //usage of two elements to convert it 
    for(int i=0;i<n;i++)
    {
        if(a[i]==e1)
          c1++;
        else if(a[i]==e2)
          c2++;
        else if(c1==0)
          e1=a[i] ,c1++;
        else if(c2==0)
         e2=a[i] ,c2++;
        else 
          c1--,c2--;        //in this case its not equal to any of the elements so both are wrong 
    }
    
    c1=0,c2=0;
    //confirming if these elements really appear n/3 times
    for(int i=0;i<n;i++)
    {
        if(a[i]==e1)
          c1++;
        else if(a[i]==e2)
          c2++; 
    }
    if(c1>(n/3))
      return e1;
    else if(c2>(n/3))
      return e2;
    else 
      return -1;    
}

  ```
</div>
