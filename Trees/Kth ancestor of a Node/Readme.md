<h2>Duplicate Subtree in a Binary Tree </h2>
<h3>Medium</h3><hr>
<div><p>Given a binary tree of size  N, a node and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.</p>



<h3>  Your Task: </h3>
<p> 

</p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> K = 2
     Node = 4
     Tree = [1 2 3 4 5]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Since, K is 2 and node is 4, so wefirst need to locate the node and
 look k times its ancestors.Here in this Case node 4 has 1 as his 2nd Ancestor aka the Root of the tree.
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
int  helper(Node *root, int node,int k,int &ans)
{
    if (!root)
        return NULL;
    
    if(root->data == node)
      return 1;
      
    int left = helper(root->left,node,k,ans);
    int right = helper(root->right,node,k,ans);
    
    if(left ==k || right==k)
      ans=root->data;
      
    if(left) return left+1;
    else if(right) return right+1;
    else return 0;
   
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans=-1;
    helper(root,node,k,ans);
    
    return ans;
       
}
  ```
</div>
