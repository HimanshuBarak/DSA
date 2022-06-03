<h2>0-1 KnapScak Problem </h2>
<h3>Medium</h3><hr>
<div><p>
  
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
     
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(N*W).
  
<strong>Space:</strong> O(N*W).
  <h2> Algorithm </h2>
 <pre>
  1. For each value of n and w we check if its possible to add wt[n] //n-1
  2. if yes we consider both cases adding and not adding it and max of it is selected
  3. If not return to weight as it is to consider the next element 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
       // Memoization Approach
  class Solution
{   int dp[1000][1000];
     
    public:
    //recursive function be like 
    Solution(){
      memset(dp,-1,sizeof(dp));  
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
          if(n==0 ||w==0)
            return 0;
          if(dp[w][n-1]!=-1)
             return dp[w][n-1];
              
          if(wt[n-1]<=w)  //include the weight or dont include it
            return dp[w][n-1]=max((val[n-1]+knapSack(w-wt[n-1],wt,val,n-1)),knapSack(w,wt,val,n-1));
          else if(wt[n-1]>w)
            return dp[w][n-1]=knapSack(w,wt,val,n-1);
    }
};
  
  
  //TOP DOWN APPROACH
  class Solution
{   
     
    public:
    //recursive function be like 
    
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        int dp[1000][1000];
        memset(dp,-1,sizeof(dp));  
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                if(i==0 ||j==0)
                 {
                     dp[i][j]=0; continue;
                 }
                 if(wt[i-1]<=j) 
                  dp[i][j] = max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
                 else 
                  dp[i][j]=dp[i-1][j];
            }
        }
          
        return dp[n][w]; 
    }
};
  ```
</div>
