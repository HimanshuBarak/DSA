<h2>Flatten a binary tree to a Linked List</h2>
<h3>Medium</h3><hr>
<div><p>
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.  

 
</p>


[Problem Link](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> root = [1,2,5,3,4,null,6]
<strong>Output:</strong> [1,null,2,null,3,null,4,null,5,null,6]
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
  /**
 
 At every node we need to make sure that the left child is pointing to the right 
 child
 
 
 
 */
class Solution {
public:
    /*
      Algoritm 1: you first visit the right child store it in a pointer 
      point left child to right child (through the stored pointer)
      root points to left child as its right child
      
      The traversal that will be done here is also called reverse traversal
    */
    TreeNode* prev=NULL;
    
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left=NULL;
        prev=root;
    }
};
  
  //Iterative Approach
  void flatten(TreeNode* root) {
        
        stack<TreeNode*> st;
        if(!root) return;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* curr =st.top(); st.pop();
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
            if(!st.empty())
            curr->right=st.top();
            curr->left=NULL;
        }
    }
  
  /*
     We should use morris traversal 
      Time => O(N) ; space =>O(1) 
    */
    
    void flatten(TreeNode* root) {
        
       TreeNode* curr=root;
        if(!curr)
            return;
        while(curr!=NULL)
        {  //go to left child
            TreeNode* temp=curr->left;
            if(!temp)
            {
                curr=curr->right;
                continue;
            }
            //find the rightmost child
            while(temp->right!=NULL){
                 temp=temp->right;
            }
             //link the left rightmost child to right tree   
            temp->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
            //after making left null traverse the right tree
            curr=curr->right;
        }
   }
  ```
</div>
