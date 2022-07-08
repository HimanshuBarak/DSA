<h2>Maximum Sum Combination</h2>
<h3>Medium</h3><hr>
<div><p>
  Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.

 
</p>


[Problem Link](https://www.interviewbit.com/problems/maximum-sum-combinations/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> A = [3, 2]
 B = [1, 4]
 C = 2
<strong>Output:</strong> [10, 9, 9, 8]
<strong>Explanation:</strong> Explanation 1:

 7     (A : 3) + (B : 4)
 6     (A : 2) + (B : 4)
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
#define f first
#define s second
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    
    
    sort(A.begin(),A.end());  //time => O(NlogN)
    sort(B.begin(),B.end());  //
    
    vector<int> res(C,0);
    int n=A.size();
    
    priority_queue<pair<int,pair<int,int>>> pq;
    
    set<pair<int,int>> st;
    st.insert({n-1,n-1});
    
    pq.push({A[n-1]+B[n-1],{n-1,n-1}}); //adding the largest value 
     
    for(int k=0;k<C;k++)  // O(C)
     {
         pair<int,pair<int,int>> p=pq.top();
         pq.pop();
         res[k]= p.first;
         
         int i=p.s.f;
         int j=p.s.s;
         
         int s1 =A[i-1]+A[j];
         int s2 =A[i]+A[j-1];
         
         pair<int,int> p1 = {i-1,j};
         pair<int,int> p2 = {i,j-1};
         
         //check if p1 is already present
         if(st.find(p1)==st.end())
         {
             pq.push({s1,p1});
             st.insert(p1);
         }
         
         //do same for p2
          if(st.find(p2)==st.end())
         {
             pq.push({s2,p2});
             st.insert(p2);
         }
     }
     return res;
}

  ```
</div>
