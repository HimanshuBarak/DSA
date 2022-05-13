

<h1> Creating a Graph and printing a graph using array of vectors and 2D vectors </h1>


``` c++

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
     
       vector<vector<int>> arr(V);
       
       for(int i=0;i<V;i++)
       {   
           arr[i].push_back(i);
           for(int j=0;j<adj[i].size();j++)
           {
               arr[i].push_back(adj[i][j]);
           }
       }
       
       
       //arrays of vector solution 
       vector<int> res[V];
       for(int i=0;i<V;i++)
       {
           //res[i]=i;
           for(auto x:adj[i])
            {
                res[i].push_back(x);
            }
       }
       
       for(int i=0;i<V;i++)
       {
           cout<<endl;
           for(auto x:res[i])
            {
                cout<<x<<" ";
            }
       }
       return arr;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>> ans = obj.printGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size() - 1; j++) {
                cout << ans[i][j] << "-> ";
            }
            cout << ans[i][ans[i].size() - 1];
            cout << endl;
        }
    }
    return 0;
}  // } Driver Code Ends

```
