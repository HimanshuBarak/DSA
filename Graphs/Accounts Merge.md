<h2>Accounts Merge</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 
</p>


[Problem Link](https://leetcode.com/problems/accounts-merge/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
<strong>Output:</strong> [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
<strong>Explanation:</strong> The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
     
<strong>Output:</strong> [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. The main algorithm for solving this question is  to solve it using a disjoint set where we consider the index of account in the disjoin set
  2. so if we are using a disjoint set then we have to take union the criteria for union will be :     
  3. we will store all nodes in a unordered_map in case an element already exists in the map then we will merge them because the node is common here
  4. that's it that's the main logic here nothing else
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class DisjointSet{
  public:  
  vector<int> rank, parent,size;
  DisjointSet(int n)
  {
    // we declare the rank array of size n+1 incase there is 1 based indexin
    rank.resize(n+1);
    // intialize each node as a parent of iteself
    parent.resize(n+1);
    // for size array
    size.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
  }
   
  void unionBySize(int u,int v)
  {
      int pU = getParent(u);
      int pV = getParent(v);
// incase they both belong to the same parent no need to perform the union
      if(pU==pV)
       return; 
       // we attach smaller rank bith bigger to decrease the overall time in finding the parent
      if(size[pV]>size[pU])
      {
          parent[pU]=pV;
          size[pV]+=size[pU];
      }
      else if(size[pU]==size[pV])
      {
          size[pU]+=size[pV];
          parent[pV]=pU;
      }else
      {
           parent[pV]=pU;
           size[pU]+=size[pV];
      }
        
  }
  
  // function to find parent of a given node
  int getParent(int v)
  {
      if(parent[v]==v)
       return v;
      else
       return parent[v] = getParent(parent[v]); // here we are doing path compression so that next time we will find the parent in O(1) time
  }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        
       int n=acc.size();

       DisjointSet ds(n);
       unordered_map<string,int> mp;

       for(int i=0;i<n;i++)
       {   
           for(int j=1;j<acc[i].size();j++)
           {     
               if(mp.find(acc[i][j])!=mp.end())
               {   
                    ds.unionBySize(mp[acc[i][j]],i);
               }
               else{
                    mp[acc[i][j]]=i;
               }
           }
       }
      
       // now we will merge all the common account ; in the previous step we have already connected the common account
       vector<vector<string>> tmp(n);
       for(auto x:mp)
       {   
           string s = x.first;
           // we find the ultimate parent for a given node
           int p = ds.getParent(x.second);
           tmp[p].push_back(s);
       }
        vector<vector<string>> res;

        for(int i=0;i<n;i++)
        {
            if(tmp[i].size()==0)
              continue;
            sort(tmp[i].begin(),tmp[i].end());  
            vector<string> ans;
            ans.push_back(acc[i][0]);
            ans.insert(ans.end(),tmp[i].begin(),tmp[i].end());  
            res.push_back(ans);  
        }
      
       return res;
    }
};
  ```
</div>
