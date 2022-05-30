<h2>Alien Dictionary</h2>
<h3> Hard</h3><hr>
<div><p>
  Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/alien-dictionary/1)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
<strong>Output:</strong> 1
<strong>Explanation:</strong> Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
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
  1. For each element in the array compare it to the next element and figure out the first different letters
  2. Make a edge of these letters and push it in the adajaceny matrix
  3. Do topological sort
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution{
    public:
    void dfs(vector<int> adj[],vector<int> &vis,int v,string &st){
          vis[v]=1;
          
          for(auto x:adj[v])
          {
              if(!vis[x])
                dfs(adj,vis,x,st);
          }
          char ch =v+97;
         // cout<<ch<<"-->";
          st.push_back(ch);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int> adj[K];
        
        for(int i=0;i<N-1;i++)
        {  
            
            string w1=dict[i];
            string w2=dict[i+1];
            for(int j=0;j<min(w1.size(),w2.size());j++)
            {
                if(w1[j]!=w2[j])
                {
                    //cout<<w1[j]<<"-->"<<w2[j]<<"==>"<<i;
                adj[w1[j]-97].push_back(w2[j]-97);
                break;
                }
               
            }
           
        }
        
        vector<int> vis(K,0);
         string res="";
        for(int i=0;i<K;i++)
        { 
            if(!vis[i])
             dfs(adj,vis,i,res);
        }
       
        reverse(res.begin(),res.end());
       // cout<<res;
        return res;
    }
};
  ```
</div>
