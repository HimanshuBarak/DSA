<h2> Predecessor and Successor </h2>
<h3>Easy</h3><hr>
<div><p>There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor or successor is not found print -1.</p>



<h3>  Your Task: </h3>
<p> 
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains n denoting the number of
  edges of the BST. The next line contains the edges of the BST. The last line contains the key.
  Print the predecessor followed by successor for the given key. If the predecessor or successor is not found print -1.
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
void findPreSuc(Node* root, Node*& pre, Node*& suc, int val)
{

// Your code goes 
     
     if(!root)
      return;
      
     //setting predeccessor
     if(root->key <val)
     {
         pre=root; //predecessor is lawasys less than current value
         findPreSuc(root->right,pre,suc,val); // we find the rightmost such smaller value
     }
     //for successor
     else if(root->key >val)
     {
         suc=root;
         findPreSuc(root->left,pre,suc,val);
     }
     else{
         //in case the key is located
         findPreSuc(root->left,pre,suc,val); 
         findPreSuc(root->right,pre,suc,val);
         
     }
     
}
  ```
</div>
