
preorder =>   root-- left--right



///////////////////////////////// Recursive Approach ////////////////////////////////////////////////////

class Solution {
public:
    void helper(TreeNode* root,vector<int> &res)
    {
         if(root==NULL)
             return ;
         res.push_back(root->val);
        
         helper(root->left,res);
         helper(root->right,res);
         
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
         
        vector<int> res;
        
         helper(root,res);
        
        
        return res;
    }
};

/////////////////////////////////////////////  Iterative Approach ////////////////////////////////////////////////////

 vector<int> preorderTraversal(TreeNode* root) {
         
        vector<int> res;
        
         stack<TreeNode*> s;
         TreeNode* curr = root;
         while(curr!=NULL || !s.empty())
         {
             while(curr!=NULL)
             {
                 res.push_back(curr->val);
                 s.push(curr);
                 curr=curr->left;
             }
             curr = s.top();
             s.pop();
             curr=curr->right;
             
             
         }
        
        return res;
    }

