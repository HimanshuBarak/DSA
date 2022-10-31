<h2>Ninja's Training</h2>
<h3>Medium</h3><hr>
<div><p>
  

 
</p>


[Problem Link](https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1)

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
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
        //Recursion 
        int solve(vector<vector<int>> &pt,int i,int last,vector<vector<int>> &dp)
    {   
         if(dp[i][last]!=-1)
            return dp[i][last]; 
        if(i==0)
        {   int maxi=0;
             for(int k=0;k<3;k++)
             {
                 if(last!=k)
                     maxi= max(maxi,pt[i][k]);   
             }
          return dp[i][last]= maxi;
         }  
        int maxi=0;
             for(int k=0;k<3;k++)
             {
                 if(last!=k)
                 {  
                     maxi= max(maxi,pt[i][k]+solve(pt,i-1,k,dp));
                 }
             }
        return dp[i][last]=maxi;
}
 int ninjaTraining(int n, vector<vector<int>> &pt)
{
   vector<vector<int>> dp(n,vector<int>(4,-1));
   return solve(pt,n-1,3,dp);
}

//Tabulation 
 int ninjaTraining(int n, vector<vector<int>> &pt)
{
    vector<vector<int>> dp(n,vector<int>(4,-1)); 
    //tabulation == reverse of memoisation ==>  last gets converted to first 
    dp[0][0] = max(pt[0][1],pt[0][2]); //if next activity is 0
    dp[0][1] = max(pt[0][0],pt[0][2]); //if next activity is 1
    dp[0][2] = max(pt[0][0],pt[0][1]);  //if next activity is 2
    dp[0][3] = max(pt[0][0],max(pt[0][1],pt[0][2])); //incase next activity is not present
      for(int i=1;i<n;i++)
      {  //next is the activity selected for the next row 
          // in the last recode this is 3 thats why this gives dp[n-1][3] gives us our final answer
        for(int next=0;next<4;next++)
         {
            for(int k=0;k<3;k++)
            {  
                if(k!=next)
                dp[i][next] = max(dp[i][next],pt[i][k]+dp[i-1][k]);
            }
         }
         
      }
     return dp[n-1][3];
}    

Space optimised kal krenge
                                 
 int ninjaTraining(int n, vector<vector<int>> &pt){
  //think in reverse 
    vector<int> temp(4,-1);
    temp[0] = max(pt[0][1],pt[0][2]);
    temp[1] = max(pt[0][0],pt[0][2]);
    temp[2] = max(pt[0][0],pt[0][1]);
    temp[3] = max(pt[0][0],max(pt[0][1],pt[0][2]));
    
    for(int i=1;i<n;i++)
    {  
      vector<int> curr(4,-1);
     for(int next=0;next<4;next++)
      {  
        for(int k=0;k<3;k++)
        {
          if(k!=next)
             curr[next] = max(curr[next],pt[i][k]+temp[k]);     
        }  
      } 
        temp=curr;
    }
    return  temp[3];
}                                
  ```
</div>
