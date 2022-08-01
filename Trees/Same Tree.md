<h2>Same Tree</h2>
<h3>Easy</h3><hr>
<div><p>
  Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 
</p>


[Problem Link](https://leetcode.com/problems/same-tree/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> p = [1,2], q = [1,null,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> p = [1,2,1], q = [1,1,2]
     
<strong>Output:</strong> false
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   class Solution {
public:
    /* we are basically comparing for which node if it matches good if it dosent
     than return false */
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL && q==NULL)
            return true;
        //is subtree of one tree is NULL and other isn't
        if((!p && q) || (p && !q)) 
            return false;
        
        if(p->val!=q->val)
            return false;
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
  ```
</div>
