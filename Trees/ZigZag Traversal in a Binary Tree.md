<h2>Zig Zag Traversal in a Binary Tree</h2>
<h3>Medium</h3><hr>
<div><p>
  Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 
</p>


[Problem Link](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[20,9],[15,7]]
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
    if level no. is even fill vector from behind else fill from front ,as simple as that
  class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(!root)
            return res;
        bool flag=true;
        queue<TreeNode* > q;
        q.push(root);
        int level=1;
        while(!q.empty())
        {
           int k=q.size();
            vector<int> temp(k,0);
            int i=0;
            int inc=1;
            if(level%2==0)
              i=k-1,inc=-1;
           while(k--)
           {
               TreeNode* curr = q.front(); q.pop();
               temp[i] =curr->val;
               i+=inc;
               if(curr->left)
                   q.push(curr->left);
               if(curr->right)
                   q.push(curr->right);
           }
            level++;
            res.push_back(temp);
        }  
        return res;
    }
};
  ```
</div>
