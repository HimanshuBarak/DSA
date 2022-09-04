<h2>Maximum Sum BST in Binary Tree</h2>
<h3>Hard</h3><hr>
<div><p>
  Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

 
</p>


[Problem Link](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
<strong>Output:</strong> 20
<strong>Explanation:</strong> Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [4,3,null,1,2]
     
<strong>Output:</strong> 2
<strong>Explanation:</strong> Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(N)
  
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
class Solution {
    int maxSum=INT_MIN;
public:
    vector<int> postorder(TreeNode* root)
    {
        if(!root)
            return {INT_MAX,INT_MIN,0};  //in the format {min,max,sum}
        
        vector<int> left(postorder(root->left));
        vector<int> right(postorder(root->right));
        
       if(left.empty() || right.empty()|| root->val <= left[1] || root->val >= right[0])       
         return {};
        
        //incase it is a BST 
        int sum = root->val+left[2]+right[2];
        
        maxSum =max(maxSum,sum); //finidng the max sum
        int  mini = min(root->val,left[0]); //mini value till now including curr
        int maxi =max(root->val,right[1]); // max value till now including curr 
        
        return {mini,maxi,sum};
    }
    
    int maxSumBST(TreeNode* root) {
        postorder(root);
        return maxSum<0?0:maxSum; //when all values are negative ans is -ve so we return 0
    }
};

/*
  
   Here we start checking if its BST from the bottom instead of the top
   we return a vector that contains the max ,min and sum value to the left and right
   now we compare the max from left and min from right if they satisfy we consider it as a BST 
   else
    we return {} which states the tree below/from  this node is not a BST
}*/
  ```
</div>
