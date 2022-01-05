<h2>Find all Duplicate Subtree in a Binary Tree </h2>
<h3>Medium</h3><hr>
<div><p>Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.</p>



<h3>  Your Task: </h3>
<p> 
You don't need to take input. Just complete the function printAllDups() that takes the root node as a parameter and returns an array of Node*, which contains all the duplicate subtree.
Note: Here the Output of every Node printed in the Pre-Order tree traversal format.
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
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= Number of Nodes &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;=Data of a Node  &lt;= 5</code></li>
</ul>
  
  <h2> Solution </h2>
  
  ``` c++ 
 string helper(Node* root, vector<Node*> &res,unordered_map<string,int> &mp)
  {
      if(!root)
       return "$";
       
      string left = helper(root->left,res,mp);
      string right = helper(root->right,res,mp);
      string s="";
       s = s +to_string(root->data)+"*"+left+"*"+right;
     
      if(mp[s]==1)
      {
          res.push_back(root); 
      }
       mp[s]++;    
      
      return s;
      
  }

vector<Node*> printAllDups(Node* root)
{
    // Code here
    vector<Node*> res;
    unordered_map<string,int> mp;
    helper(root,res,mp);
    return res;
}
  ```
</div>
