<h2>Construct Tree from Inorder & Preorder </h2>
<h3>Medium</h3><hr>
<div><p>Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. </p>



<h3>  Your Task: </h3>
<p> 
Your task is to complete the function <code>buildTree()</code> which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)
</p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> inorder[] = {3 1 4 0 5 2}
       preorder[] = {0 1 3 4 2 5}
<strong>Output:</strong> 3 4 1 5 2 0
<strong>Explanation:</strong> Draw the resultant Tree
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> inorder[] = {1 6 8 7}
      preorder[] = {1 6 7 8}
<strong>Output:</strong> 8 7 6 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= Number of Nodes &lt;= 10<sup>3</sup></code></li>
	
</ul>
</div>
