

Inorder Traversal =>  left - root - right


Recursive approach ----------------------------------------------------
```c++
class Solution {
public:
    void inorder(TreeNode* root ,vector<int> &res)
    {   
        if(root!=NULL)
        {
             inorder(root->left,res);
            res.push_back(root->val);
            inorder(root->right,res);
        } 
       
        
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
         
          vector<int> res;
         inorder(root,res);
        
          
         return res;
    }
};

```
/////////////////////////////////////////////// Iterative Approach ///////////////////////////////////////////////
``` c++
class Solution {
public:
   
    vector<int> inorderTraversal(TreeNode* root) {
         
          vector<int> res;
          stack<TreeNode*> s;
          TreeNode* curr = root; 
          while(curr!=NULL || !s.empty())
          {
              while(curr!=NULL)           //store left first thus it reads left first and than it read root and then later we add the right
              {
                  s.push(curr);
                  curr=curr->left;
              }
              curr = s.top();
              s.pop();
              res.push_back(curr->val);
              
              curr=curr->right;
          }
          
         return res;
    }
};
```
