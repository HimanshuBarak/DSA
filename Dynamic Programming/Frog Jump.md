<h2>Frog Jump</h2>
<h3>Easy</h3><hr>
<div><p>
  

 
</p>


[Problem Link](https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)

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
  1. 
  2.
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
    
 // Recursive Solution =>  Time - O(N)  ,Space - O(N)
  #include <bits/stdc++.h> 

int dp[100001];

int solve(vector<int> &A,int i){
    if(i==0)
        return 0;
    
    if(dp[i]!=-1)
        return dp[i];
    
    int one = abs(A[i]-A[i-1])+solve(A,i-1);
    int two =INT_MAX;
    if(i!=1)
     two = abs(A[i]-A[i-2])+solve(A,i-2);
    return dp[i]=min(one,two);
}
 int frogJump(int n, vector<int> &A)
{
    // Write your code here.
       memset(dp,-1,sizeof(dp));
  
     return solve(A,n-1);
  
  

  //Tabulation  O(N) - Time , O(N) - Space

  #include <bits/stdc++.h> 
int frogJump(int n, vector<int> &A)
{
    // Write your code here.
       int dp[100001];
       memset(dp,-1,sizeof(dp));
        dp[0]=0;
       for(int i=1;i<n;i++)
       {
           if(i==1)
               dp[i]=abs(A[i]-A[i-1]);
           else
        dp[i]= min(abs(A[i]-A[i-1])+dp[i-1],abs(A[i]-A[i-2])+dp[i-2]);
       }
      return dp[n-1];
}
                            
//Tabulation O(1) Space 
      int frogJump(int n, vector<int> &A)
{
    int prev1=0,prev2=0;
    
    int ans=0;
    if(A.size()>=2)
      prev1=abs(A[1]-A[0]);  
       
       for(int i=2;i<n;i++)
       {
        ans= min(abs(A[i]-A[i-1])+prev1,abs(A[i]-A[i-2])+prev2);
           prev2=prev1;
           prev1=ans;
       }
      return ans;
}                      
  ```
</div>
