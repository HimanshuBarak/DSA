<h2>Construct Tree from Inorder and Postorder Traversal</h2>
<h3>Medium</h3><hr>
<div><p>
  

 
</p>


[Problem Link](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Very Similar to Inorder and Preorder one ,you just need to change the order
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution {
public:
      TreeNode* makeTree(vector<int> &postorder,vector<int>& inorder,int l,int r,int &i){
        
        //base condition
        if(l>r ||i<0)
            return NULL;
        int k=l;
        while(inorder[k]!=postorder[i]) k++;
        
        TreeNode* root = new TreeNode(postorder[i--]);
        
         root->right = makeTree(postorder,inorder,k+1,r,i);
        root->left = makeTree(postorder,inorder,l,k-1,i);
       
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i=postorder.size()-1;
      return   makeTree(postorder,inorder,0,inorder.size()-1,i);
    }
};
  ```
</div>
