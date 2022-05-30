<h2>Clone a Graph</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>
<strong>Output:</strong> 
<strong>Explanation:</strong> 
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
  1. Maintain Hashmap 
  2. Do dfs
  3. Hogya
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
 /*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        //check if the node has already been cloned 
        if(mp.find(node)==mp.end())
        {
            mp[node] = new Node(node->val,{}); //created a new node
            //adding the nodes neighbour
            for(Node* neighbors:node->neighbors)
            {
                mp[node]->neighbors.push_back(cloneGraph(neighbors));
            }
        }
        
        return mp[node];
    }
};
  ```
</div>
