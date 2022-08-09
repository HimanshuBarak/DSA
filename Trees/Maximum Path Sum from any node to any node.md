<h2>Maximum Path sum from any node to any node</h2>
<h3>Hard</h3><hr>
<div><p>
  A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.

 
</p>


[Problem Link](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> root = [1,2,3]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [-10,9,20,null,null,15,7]
     
<strong>Output:</strong> 42
<strong>Explanation:</strong> The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1.  the values are negative also ,so if either left or right child is negative dont consider it (take it as 0)
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution {
public:
    int ans=INT_MIN;
    
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        left = left<0?0:left;
        right =right<0?0:right;
        
        int curr = left+ root->val+right;
        ans=max(ans,curr);
        
        return root->val+max(left,right);
        
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans==INT_MIN?0:ans;
    }
};
  ```
</div>
