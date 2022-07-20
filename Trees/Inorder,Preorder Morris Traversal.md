<h2>Inorder Morris Traversal</h2>
<h3>Medium</h3><hr>
<div><p>
  Do inorder and preorder travresal in constant space using morris traversal

 
</p>


[Problem Link]()

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
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
    //Inorder Traversal
     class Solution {
    
    //Morris Traversal Time => O(n) Space=> O(1)
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        TreeNode* curr = root;
        vector<int> res;  
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                //if there is no left than root should be printed in order
                res.push_back(curr->val);
                curr=curr->right;
            }else{
                //in case there is left find rightmost node nd form link
                TreeNode* prev = curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                    
                //in case there is no link make it (first time visiting)
                if(!prev->right)
                {
                    prev->right=curr; //making link
                    curr=curr->left; // moving to next node
                }else
                {  //the link is already there (second time visiting) left subtree visited
                    prev->right=NULL;
                    res.push_back(curr->val); 
                    curr=curr->right; //move to right subtree
                }
            }
        }
        return res;
    }
};
  
  //Preorder Traversal
  class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> res;
        
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                //if there is no left than root should be printed in order
                res.push_back(curr->val);
                curr=curr->right;
            }else{
                //in case there is left find rightmost node nd form link
                TreeNode* prev = curr->left;
                
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                    
                //in case there is no link make it (first time visiting)
                if(!prev->right)
                {
                    prev->right=curr; //making link
                    res.push_back(curr->val);
                    curr=curr->left; // moving to next node
                }else
                {  //the link is already there (second time visiting) left subtree visited
                    prev->right=NULL;      
                    curr=curr->right; //move to right subtree
                }
            }
        }
        return res;
    }
};
  ```
</div>
