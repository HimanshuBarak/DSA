<h2>Pow(x,n)</h2>
<h3>Medium</h3><hr>
<div><p>
  Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
</p>


[Problem Link](https://leetcode.com/problems/powx-n/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> x = 2.00000, n = 10
<strong>Output:</strong> 1024.00000
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> x = 2.00000, n = -2
     
<strong>Output:</strong> 0.25000
<strong>Explanation:</strong> 2-2 = 1/22 = 1/4 = 0.25
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
    double myPow(double x, int n) {
        /*
          // Iterative Solution
        if(n==0)
            return 1;
        long p =n;
        if(p<0)
            p=-p;
        double ans=1;
        while(p)
        {
            if(p%2==0)  //power is even
            {
                x=x*x;  // 4^4 can be written as 16^2
                p=p/2; 
            }else
            {
                ans=ans*x;  //2^5 => 2*2^4
                p--;
            }
        }
        if(n<0) ans=1/ans;
        
        return ans;
        */
        //recursive approach
        if(n==0){
            return 1;
        }
        if(n<0)
        {
            n=abs(n);
            x=1/x;
        }
        if(n%2==0)
            return myPow(x*x,n/2);
        else
            return x*myPow(x*x,n/2);
    }
};
  ```
</div>
