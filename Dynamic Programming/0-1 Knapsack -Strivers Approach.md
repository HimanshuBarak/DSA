<h2>0-1 Knapsack</h2>
<h3>Easy</h3><hr>
<div><p>
  

 
</p>


[Problem Link](https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)


  <h2> Solution </h2>
  
  ``` c++ 
   
  //Recurisve Approach
  
  int solve(vector<int> &w, vector<int> &val, int i, int W,vector<vector<int>> &dp){
    if(i==0)
    {
        if(w[i]<=W)
            return  val[i];
        else
            return 0;
    }
    if(dp[i][W]!=-1)
        return dp[i][W];
    int take=0;
    if(w[i]<=W)
        take =   val[i]+solve(w,val,i-1,W-w[i],dp); //take 
    
   return dp[i][W]= max(take,solve(w,val,i-1,W,dp));  // notTake
}

//Tabulation
  
  int knapsack(vector<int> w, vector<int> val, int n, int W) 
{   
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    for(int i=w[0];i<=W;i++){
        dp[0][i]= val[0];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=W;j++)
        {
           int take=0;
            if(w[i]<=j)
                take =   val[i]+dp[i-1][j-w[i]]; //take 

           dp[i][j]= max(take,dp[i-1][j]); 
        }
    }
	return dp[n-1][W];
}
  //Space Optimised Approach 
  int knapsack(vector<int> w, vector<int> val, int n, int W) 
{   
    vector<int> prev(W+1,0);
    vector<int> curr(W+1,0);
    for(int i=w[0];i<=W;i++){
        prev[i]= val[0];
    }
    
    for(int i=1;i<n;i++)
    {  
        for(int j=0;j<=W;j++)
        {
           int take=0;
            if(w[i]<=j)
                take =   val[i]+prev[j-w[i]]; //take 

           curr[j]= max(take,prev[j]); 
        }
        prev=curr;
    }
	return prev[W];
}
  //we can further optimise space here coz it we always look for in the left
   
  int knapsack(vector<int> w, vector<int> val, int n, int W) 
{   
    vector<int> prev(W+1,0);
    for(int i=w[0];i<=W;i++){
        prev[i]= val[0];
    }
    
    for(int i=1;i<n;i++)
    {  
        for(int j=W;j>=0;j--)
        {
           int take=0;
           int notTake=prev[j]; 
            if(w[i]<=j)
                take =   val[i]+prev[j-w[i]]; //take 

           prev[j]= max(take,prev[j]); 
        }
        
    }
	return prev[W];
}
  ```
</div>
