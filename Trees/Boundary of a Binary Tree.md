
<p>
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

<strong> Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. </strong> 

This means that if the root has no right child the right border will be the root node itself see the example in the gfg question
</p>

 

Your Task:
This is a function problem. You don't have to take input. Just complete the function boundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

 

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

 

<h4> Constraints: </h4>

<p> 1 ≤ Number of nodes ≤ 105 </p>
<p> 1 ≤ Data of a node ≤ 105  </p>



















//////////////////////////////// Solution //////////////////////////////////////////////////////////
```c++

 //see 2nd example of gfg carefully and then u will understand why root is added separately 
class Solution {
public:
    bool leafNode(Node *root)
    {
        if(!root->left && !root->right)
          return true;
        else
          return false;
    }
    void addLeftBoundary(Node* root, vector<int> &res) {
        Node* cur = root->left;
        while (cur) {
            if (!leafNode(cur)) res.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    void addLeaves(Node* root, vector<int>& res) {
        if (leafNode(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }
    void addRightBoundary(Node* root, vector<int> &res) {
        Node* cur = root->right;
        vector<int> tmp;
        while (cur) {
            if (!leafNode(cur)) tmp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = tmp.size()-1; i >= 0; --i) {
            res.push_back(tmp[i]);
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        
        vector<int> res;
       
       
        if(!root)
         return res;
         if (!leafNode(root)) res.push_back(root->data); 
         //the above inclusiion has done to be done separatelu
         //coz in case of there is no left node if not done separartely teh right subtree gets included
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
        
      
        
        return res;
    }
};
```
