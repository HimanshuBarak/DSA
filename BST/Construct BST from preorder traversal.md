<h2>Construct BST from preorder</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
 
</p>


[Problem Link](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> preorder = [8,5,1,7,10,12]
<strong>Output:</strong> [8,5,10,1,7,null,12]
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
   class Solution {
public:
    //this solution will take O(N*N) Wwor worst case imagine test case [7,5,4,3,2]
    //average time case would be O(n)*log(n)
    TreeNode* solve(vector<int>& nums ,int &i,int bound)
    {
        if(i>=bound)
            return NULL;
        
        TreeNode* temp = new TreeNode(nums[i++]);
        int k=i;
        
        //we find the left subtree (it will have elements greater than curr)
        while(k<bound && nums[k]<nums[i-1])k++;
        temp->left=solve(nums,i,k); //pass left subtree range to left child
        temp->right=solve(nums,i,bound); //pass right subtree range to right child
        
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& nums) {
        int i=0;
        return solve(nums,i,nums.size());
    }
};
  
  
  //Optimal Solution
  class Solution {
public:
    /* the concept is this for each node the left children should be smaller
     and right larger  in preorder as the left child comes first we will
     traverse them first  if element is larger than parent return NULL
     for right children the parent in INT_MAX
    
    */
    //average time case would be O(n)
    TreeNode* solve(vector<int>& nums ,int &i,int bound)
    {
        if(i==nums.size() || nums[i]>bound)
            return NULL;
        TreeNode* temp = new TreeNode(nums[i++]);
    
        temp->left=solve(nums,i,nums[i-1]); 
        temp->right=solve(nums,i,bound); 
        
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& nums) {
        int i=0;
        return solve(nums,i,INT_MAX);
    }
};
  ```
</div>
