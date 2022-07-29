<h2>Width of a Binary Tree</h2>
<h3>Medium</h3><hr>
<div><p>
  Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 
</p>


[Problem Link](https://leetcode.com/problems/maximum-width-of-binary-tree/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> root = [1,3,2,5,3,null,9]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The maximum width exists in the third level with length 4 (5,3,null,9).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1,3,2,5,null,null,9,6,null,7]
     
<strong>Output:</strong> 7
<strong>Explanation:</strong> The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7)
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        //do level order traversal but do it properly
        
        queue<pair<TreeNode*,long>> q;
        long res=0;
        q.push({root,0});
        
        while(!q.empty())
        {
            long start=-1,end=-1;
            int k=q.size();
            while(k--)
            {  pair<TreeNode* ,int> p = q.front(); q.pop();
                TreeNode* curr=p.first;
                long index = p.second;
             
                if(start==-1)
                    start=index;
                end=index;
              if(curr->left)
                  q.push({curr->left,2*index+1});
              
             if(curr->right)
                  q.push({curr->right,2*index+2});
            }
            
            res=max(res,end-start+1);
        }
            
        return res;    
    }
};
  ```
</div>
