<h2>Vertical Order Traversal of a Binary Tree</h2>
<h3>Hard</h3><hr>
<div><p>
  
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
 
</p>


[Problem Link](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>  root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[9],[3,15],[20],[7]]
<strong>Explanation:</strong> Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1,2,3,4,5,6,7]
     
<strong>Output:</strong> [[4],[2],[1,5,6],[3],[7]]
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. We are basically doing level order traversal and storing the values column wise and then level vise and then value wise
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
#define f first
#define s second;
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //col //row //smallest element
        map<int,map<int,multiset<int>>> nodes;
        
        queue<pair<TreeNode *,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
             int k=q.size();
            while(k--)
            {
              pair<TreeNode *,pair<int,int>> p =q.front(); q.pop();
              int x =p.second.first ,y = p.second.second ;
                // x is col
                // y is level
                TreeNode* curr = p.first;
                nodes[x][y].insert(curr->val);
                
                if(curr->left)
                    q.push({curr->left,{x-1,y+1}});
                 if(curr->right)
                    q.push({curr->right,{x+1,y+1}});
                
            }
        }
        vector<vector<int>> res;
        for(auto p:nodes)
        {   vector<int> col;
            for(auto x:p.second)
            {
                col.insert(col.end(),x.second.begin(),x.second.end());
            }
         res.push_back(col);
        }
        
        return res;
    }
};
  ```
</div>
