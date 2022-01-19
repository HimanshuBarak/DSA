<h2>Print all K Sum Paths in a Binary Tree </h2>
<h3>Easy</h3><hr>
<div><p>Given a Binary Search Tree and a node value X, find if the node with value X is present in the BST or not.</p>



<h3>  Your Task: </h3>
<p> 
You don't need to read input or print anything. Complete the functionsearch()which returns true if the node with value x is present in the BSTelse returns false.
</p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>
<strong>Output:</strong> 
<strong>Explanation:</strong> T
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
bool search(Node* root, int x) {
    // Your code here
     
     Node* curr= root;
     
     while(curr!=NULL)
     {
         if(curr->data==x)
           return true;
         if(x<curr->data)
          curr=curr->left;
         else
         curr=curr->right;
     }
     
     return false;
}

  ```
</div>
