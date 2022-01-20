<h2>Min and Max Value in a Binary Tree</h2>
<h3>Easy</h3><hr>
<div><p>Given a Binary Search Tree. The task is to find the minimum element in this given BST.</p>



<h3>  Your Task: </h3>
<p> 
The task is to complete the function minValue() which takes root as the argument and returns the minimum element of BST. If the tree is empty, there is no minimum elemnt, so retutn -1 in that case.
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
int minValue(Node* root) {
    // Code here
    
    Node* curr= root;
    int min =0;
    while(curr!=NULL)
     {
         min = curr->data;
         curr=curr->left;
     }
     return min;
}

  ```
</div>
