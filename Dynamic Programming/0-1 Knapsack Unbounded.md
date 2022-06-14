<h2> 0-1 Knapsack Unbounded</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
<strong>Output:</strong> 3
<strong>Explanation:</strong> 1.Pick the 2nd element thrice.
2.Total profit = 1 + 1 + 1 = 3. Also the total 
  weight = 1 + 1 + 1  = 3 which is <= W.
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
  1. This is quite similar to  0/1 kanpsack
  2. the difference being here once you select on element you again try if the element can be selected
  3. For bottom up we take i instead of i-1 coz we want to access the sum of current term(iske upr current vali ko dubara add krna ,instead of doing
  4. i-1 and addign onto the sum of previous terms
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution{
public:
  int dp[1001][1001];
  Solution(){
      memset(dp,-1,sizeof(dp));   
  }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        if(n==0 ||w==0)
          return 0;
        if(dp[n][w]!=-1)
           return dp[n][w];
        if(wt[n-1]<=w)
        {
            return dp[n][w]=max(val[n-1] +knapSack(n,w-wt[n-1],val,wt),knapSack(n-1,w,val,wt));
        }else
          return dp[n][w] =knapSack(n-1,w,val,wt);
    }
};

//Bottom UP Approach
 int knapSack(int n, int w, int val[], int wt[])
    {
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp)); 
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++){
               
                if(i==0 || j==0){
                   dp[i][j]=0; continue;  
                }
               else if(wt[i-1]<=j)
                {
                  dp[i][j]= max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);//same row m chayie iss term ka
                }else
                   dp[i][j] = dp[i-1][j];
                }
        }
        
       
    }
  ```
</div>
