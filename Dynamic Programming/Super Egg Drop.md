<h2>Super Egg Drop</h2>
<h3>Hard</h3><hr>
<div><p>
  You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 
</p>


[Problem Link](https://leetcode.com/problems/super-egg-drop/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> k = 1, n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
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
  1. Base Cases are good if 0 or 1 floor return as it is
  2. If one egg we can't take any chances we have to start from first floor and check for each floor
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
     int dp[200+1][10000+1];
    Solution(){
       memset(dp,-1,sizeof(dp)); 
    }
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int superEggDrop(int e, int f) 
    { 
        //if floors are 0 or 1 no more need to check further
        if(f==0 ||f==1)
          return f;
        //if one egg left we will start from bottom and do the maximum attemps
        if(e==1)
          return f;
        
        if(dp[e][f]!=-1)
          return dp[e][f];
        
         int ans=1000000;
         int l=1,r=f;
         while(l<=r)
         {
               int mid =(l+r)/2;
              //egg  breaks
              int low = superEggDrop(e-1,mid-1); 
              //egg doesnt break
              int high = superEggDrop(e,f-mid);
             if(low<high) //this done so because we are looking for the worst case
                  l=mid+1;
              else
                  r=mid-1;
        
              int temp = 1+max(low,high); //delecting worst case
              //f-k because k starts from 1 so f-k floors left ans we start from 1
              //max because we want the ans for the worst case
              ans=min(ans,temp);
            
          }
          return dp[e][f]=ans;
    }
};
  ```
</div>
