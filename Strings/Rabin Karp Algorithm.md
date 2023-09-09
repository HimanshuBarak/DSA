<h2>Rabin Karp Algorithm</h2>
<h3>Medium</h3><hr>
<div><p>
  Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurences of pattern string in the text string. 
  For printing, Starting Index of a string should be taken as 1

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> S = "batmanandrobinarebat", pat = "bat"
<strong>Output:</strong> 1 18
<strong>Explanation:</strong> The string "bat" occurs twice
in S, one starts are index 1 and the other
at index 18. 
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
   Worst case => O(m*n)
   Average Case => O(m+n)
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
 vector <int> search(string pat, string txt)
        {
            //code here.
            
            int p= 0;
            int t=0;
            int d = 256;
            int m = pat.size();
            int n = txt.size();
            int h =1; //it will store the power of the last character
            int q =INT_MAX;
            vector<int> res;
            for(int i=0;i<m-1;i++)
            {
                h= (h*d)%q;
                
            }
            
            //calculate hash values for the intial pattern
            for(int i=0;i<m;i++)
            {
                p = (d*p+pat[i])%q;
                t = (d*t+txt[i])%q;
            }
            
            
            for(int i=0;i<=n-m;i++)
            {   
                // if hash values are equal
                
                 if(p==t)
                 {
                     //verify if the patter exists or not
                     int j=0;
                     for(;j<m;j++)
                     {
                         if(pat[j]!=txt[i+j])
                           break;
                     }
                     if(j==m)
                      res.push_back(i+1);
                 }
                 if(i<n-m){
                       t = (d*(t-txt[i]*h)+txt[i+m])%q;
                 
                 // incase t becomes negative
                 if(t<0)
                  t+=q;
                 }
                 //shift the hash 
               
                 
            }
            
            if(res.size()==0)
              return {-1};
            else
              return res;
        }
  ```
</div>
