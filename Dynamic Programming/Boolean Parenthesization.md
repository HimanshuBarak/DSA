<h2></h2>
<h3></h3><hr>
<div><p>
  
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1/#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>  N = 7
S = T|T&F^T
<strong>Output:</strong> 4
<strong>Explanation:</strong> The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T))
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
  1. Find no. of ways to get true and false for each operator and proceed accordingly
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution{
public:
     unordered_map<string,int> mp;
    //whatta a dp problem 
    int solve(string &s ,int i, int j,bool istrue)
    {
        //base condition
        if(i>j)
        return 0;
    //if just one character is left we check is it the same as isTrue variable and return accordingly
        if(i==j)
        {
           if(istrue)  // if desired result is true ,return 0 or 1 based on s[i] value         
            return s[i]=='T';
           else  //if desired result is false return 
            return s[i]=='F';
        }
        // making the key
        string key = to_string(i)+" "+to_string(j)+" "+to_string(istrue);
        
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }  
        int ans=0;
        for(int k=i+1;k<j;k=k+2)
        {
            int lt = solve(s,i,k-1,true); //no ways to get true on left expression
            int lf = solve(s,i,k-1,false); //no ways to get false on left expression
            int rt = solve(s,k+1,j,true);
            int rf = solve(s,k+1,j,false);
            
            //if operator is => |
            if(s[k]=='|')
            {
                if(istrue)
                    ans= ans+ lt*rf + lf*rt + lt*rt;
                else
                  ans =ans+ lf*rf;
            }
            else if(s[k]=='&'){
                if(istrue)
                  ans = ans + lt*rt;
                else 
                  ans = ans+ lt*rf + lf*rt + lf*rf;
            }else if(s[k]=='^'){
                 if(istrue)
                  ans = ans + lf*rt + lt*rf;
                 else
                  ans = ans+ lt*rt + rf*lf;
              }
        }
        return mp[key]=ans%1003;  //question m likha h mod krne ko
    }
    
    int countWays(int n, string s){
        
        mp.clear();
        return solve(s,0,n-1,true)%1003;
    }
};
  ```
</div>
