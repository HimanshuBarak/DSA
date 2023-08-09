

<h1> Breadth First Search Traversal of a Graph </h1>

<p><strong>Complexities:</strong></p>
<strong>Time:</strong>  O(V+ E) => each vertex gets visited once and in total 2E neigbors are traversed
<strong>Space:</strong>  O(V)
``` c++
 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        //to store the visted vertex so that they aren't visited again
         vector<bool> vis(V,false);
         
         vector<int> res;
         queue<int> q;     
         q.push(0);
           
         while(!q.empty()){
               
               int v = q.front(); 
               q.pop();
               res.push_back(v);
               
               for(auto x:adj[v])
               {
                   if(!vis[x])
                   {
                       vis[x]=true;
                       q.push(x);
                   }
               }
           }    
          return res;
    }

```
