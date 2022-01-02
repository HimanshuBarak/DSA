<h2>Min distance between two given nodes of a Binary Tree </h2>
<h3>Medium</h3><hr>
<div><p>Given a binary tree and two node values your task is to find the minimum distance between them.</p>



<h3>  Your Task: </h3>
<p> 
You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the Tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.
</p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> 
<strong>Output:</strong> 
<strong>Explanation:</strong> Preorder
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
    int data;
    Node* left, * right;
}; 

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    
    Node* getlca(Node *root,int a,int b)
    {
        if(root==NULL || root->data==a || root->data==b)
         return root;
         
        Node* left = getlca(root->left,a,b);
        Node* right = getlca(root->right,a,b);
        
        if(left==NULL)
         return right;
        if(right==NULL)
         return left;
        else 
          return root;
         
        
    }
    int helper(Node* root,int a)
    {
        if(!root)
         return 0;
        
        if(root->data==a)
         return 1;
        
        int l=helper(root->left,a);
        int r=helper(root->right,a);
        
         if(l+r>0)
          return l+r+1;
         else 
          return 0;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        if(!root)
         return 0;
        //we first find the lca for the 2 given nodes 
        Node* lca = getlca(root,a,b);
        // we can than find the distance of the 2 nodes form the lca this will be our minimum distance as well
        return helper(lca,a)+helper(lca,b)-2;
    }
};
  ```
</div>
