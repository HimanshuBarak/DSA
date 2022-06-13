<h2>Target Sum</h2>
<h3>Medium</h3><hr>
<div><p>
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 
</p>


[Problem Link](https://leetcode.com/problems/target-sum/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p> 

      
 
<pre><strong>Input:</strong> nums = [1,1,1,1,1], target = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
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
   -1 + 1+ 1+ 1+1 =3;
       
       (4) - (1) = 3  => translates the count of subset sum with a given differnce
        
        (subset of positive terms) - (subset of negative terms)
    
    S1 -S2 = target
    
    S1 + S2  = sum
    
    2S1 = target +sum
    
    S1 = (target+sum)/2;  
    
    we start j with 0 to take care of the 0 inputs
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution {
public:
    int findTargetSumWays(vector<int>& a, int tar) {
        
        int sum=0;
        for(auto x:a){
            sum+=x;
        }
        /*
       
        */
        if(abs(tar)>sum || (tar+sum)%2!=0 )
            return 0;
        sum=(tar+sum)/2;
        /* We just need to find the total number of subset that contain the given sum 
        This reduces to subset sum problem
        
        For column 0 
        for each value of n we can one subset {} (the empty subset) with the sum as 0
        */
        int n = a.size();
        int dp[21][1001];
       // memset(dp,0,sizeof(dp));
        for(int i=0;i<=sum;i++)
            dp[0][i]=0;
       dp[0][0] =1;
        
       // Here we start the inner loop from j=0 this is because
        // here the input value can also be zero 
        
        for(int i=1;i<=n;i++){
           for(int j=0;j<=sum;j++)
            {
                if(a[i-1]<=j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
                else
                 dp[i][j] = dp[i-1][j];   
            } 
        }
            
            
      return dp[n][sum];
    }
};
  ```
</div>
