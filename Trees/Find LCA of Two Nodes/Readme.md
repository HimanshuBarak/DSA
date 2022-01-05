<h2>Find LCA of Two Nodes</h2>
<h3>Medium</h3><hr>
<div><p>Given a Binary Tree with all unique values and two nodes valuen1 and n2. The task is to find the lowestcommon ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them is present</p>



<h3>  Your Task: </h3>
<p> 
You don't have to read input or print anything. Your task is tocomplete the function lca()that takes nodes, n1, and n2 as parameters and returns LCA node as output. Otherwise return a node with value -1 if both n1 and n2 is not present in the tree.
</p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> n1 = 2 , n2 = 3 Tree = 1 2 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n1 = 3 , n2 = 4  Tree = 5 2 N 3 4
     
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= Number of Nodes &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;=Data of a Node  &lt;= 10<sup>5</sup></code></li>
</ul>
  
  <h2> Solution </h2>
  
  ``` c++ 
 class Solution
{
    public:
    //
    
    
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //if you locate one of the nodes than return it else reurn null
       if(root==NULL || root->data==n1 || root->data==n2)
        return root;
        
       Node* left =lca(root->left,n1,n2);    
       Node* right =lca(root->right,n1,n2);
       
       if(left==NULL)
        return right;
       else if(right==NULL)
        return left;
       else //incase both of them are not null
       return root;
       
       
    }
};
  ```
</div>
