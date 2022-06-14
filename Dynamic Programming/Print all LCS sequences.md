<h2>Print all LCS sequence</h2>
<h3>Medium</h3><hr>
<div><p>
  
You are given two strings s and t. Now your task is to print all longest common sub-sequences in lexicographical order.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1/#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> s = abaaa, t = baabaca
<strong>Output:</strong> aaaa abaa baaa
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(n^4)
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
   1. Find length of the common longest subsequence
	 2. traverse through the strings
	 3. if two letters match find the subsequence length
	 4. if length ==lcs and string hasn't alreadhy been traversed add it 
	 5. sort the resultant array to get it in lexigraphical order
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution
{
	public:
	    unordered_set<string> st;
	   //this function finds the length of the lcs
	    int findlcs(string s,string t)
	    {
	        int n=s.size();
             int m=t.size();
             int dp[n+1][m+1];
             
             memset(dp,-1,sizeof(dp));
             for(int i=0;i<=n;i++){
                 for(int j=0;j<=m;j++){
                     if(i==0 || j==0)dp[i][j]=0;
                     else if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
                     else {
                         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                     }
                 }
             } 
             return dp[n][m];
	    }
	    //this function prints the lcs
	    void helper(string s,string t,int i,int j,int lenLeft,string &temp,vector<string> &res){
	        //this means the current subsequence has reached its end
	        if(lenLeft==0){
	            if(st.find(temp)==st.end()){
	                st.insert(temp);  //to avoid duplication
	                res.push_back(temp);
	            }
	           return;   
	        }
//if the length of common sequenc is less than lcs but one of the string is fully visited,end stuff 
	        if(i>=s.size() || j>=t.size()) 
	           return;
	       //we check for the next common letter of the subsequence, picking up from previous matched letters    
	       for(int r=i;r<s.size();r++){
	           for(int c=j;c<t.size();c++)
	           {
	               if(s[r]==t[c]) //if the letter is common to boht the substrings
	               {
	                   temp.push_back(s[r]); //then it will be in the subsequence
	                   helper(s,t,r+1,c+1,lenLeft-1,temp,res);
	                   temp.pop_back();
	               }
	           }
	       }    
	    }
		vector<string> all_longest_common_subsequences(string s, string t)
		{   
		   vector<string> res;
		    string temp="";
		    int x = findlcs(s,t);
		    helper(s,t,0,0,x,temp,res);
		   sort(res.begin(),res.end());   
		   return res;     
		}
};
  ```
</div>
