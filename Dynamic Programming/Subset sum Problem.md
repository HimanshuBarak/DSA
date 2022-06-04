<h2>Subset Sum Problem</h2>
<h3>Medium</h3><hr>
<div><p>
  Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

 
</p>


[Problem Link]()

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
<strong>Output:</strong> 1
<strong>Explanation:</strong> Here there exists a subset with
sum = 9, 4+3+2 = 9.
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
  1. Exactly same as knapsack problem
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution{   
public:
    int dp[101][10001];
    Solution(){
        
       memset(dp,-1,sizeof(dp)); 
    }
    /* if you set the dp array as simple true false  and intialize everything false 
    it will be hard to keep track of whether a x,y is visited or if its just giving false
    
    */
    bool helper(vector<int>arr, int sum,int n)
    {
         if(sum==0)
          return 1;
         if(n==0)
          return 0;
        
        if(dp[n][sum]!=-1)
          return dp[n][sum];
        if(arr[n-1]<=sum)
         {
              return dp[n][sum]= (helper(arr,sum,n-1)||helper(arr,sum-arr[n-1],n-1));
              
         }
         else
          return dp[n][sum]=helper(arr,sum,n-1);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
       int n=arr.size();
       return helper(arr,sum,n);
    }
};
  
  //Top DOWN Approach
  bool isSubsetSum(vector<int>arr, int sum){
        // code here 
       int n=arr.size();
       int dp[101][10001];
       memset(dp,0,sizeof(dp));
       
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=sum;j++)
           {
              if(i==0) dp[i][j]=0;
              if(j==0) dp[i][j]=1;
           }
       }
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=sum;j++)
           {
              if(arr[i-1]<=j)
               dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
               //basically transalates to not include(take the previous one) or include
               // j- arr[i-1] checks if curr element - sum is a valid element
              else
               dp[i][j] = dp[i-1][j];
           }
       }       
       return dp[n][sum];
    }
  ```
</div>
