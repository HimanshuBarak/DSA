<h2>Duplicate Subtree in a Binary Tree </h2>
<h3>Medium</h3><hr>
<div><p>Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.</p>



<h3>  Your Task: </h3>
<p> 
You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only arguement and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.
Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.
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
  struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};

class Solution {
  public:
  int k=0;
  unordered_map <string ,int> mp;
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    
    
    string helper(Node* root)
    {
        if(root==NULL)
         return "$"; //this will help us in indication no node ## wrong pattern matching
         
         string s="";
         
         //in case the current node is a leaf node
         
         if(!root->left && !root->right)
           {
               s=to_string(root->data);
               return s;
           }
       
         //if not a leaf node
         
         s=s+to_string(root->data);
         s=s+ helper(root->left);
         s=s+ helper(root->right);
         mp[s]++;
         return s;
        
       
    }
    int dupSub(Node *root) {
         // code here
         mp.clear();
         helper(root);
         
         for(auto i:mp)
          {
              if(i.second>=2)
               return 1;
          }
          return 0;
    }
};
  ```
</div>
