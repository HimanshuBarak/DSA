<h2>Duplicate Subtree in a Binary Tree </h2>
<h3>Medium</h3><hr>
<div><p>Given two Binary Trees. Check whether they are Isomorphic or not.

Note: 
Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.</p>



<h3>  Your Task: </h3>
<p> 
You don't need to read input or print anything. Your task is to complete the function isomorphic() that takes the root nodes of both the Binary Trees as its input and returns True if the two trees are isomorphic. Else, it returns False. (The driver code will print Yes if the returned values are true, otherwise false.)
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
 class Solution{
  public:
   
    
    bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.
      if(root1==NULL && root2==NULL)
        return true;
      if(root1==NULL || root2==NULL)    
       return false;
      if(root1->data != root2->data)
       return false;
      return (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right)) || (isIsomorphic(root1->right,root2->left) &&isIsomorphic(root1->left,root2->right)); 
    }
};
  ```
</div>
