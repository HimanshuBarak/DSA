<h2>Two Sums IV- Input is a BST </h2>
<h3>Medium</h3><hr>
<div><p>
  Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

 
</p>


[Problem Link](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> 
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(N)
  
<strong>Space:</strong> O(H)  H => height of the tree 
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


/* Algorithm 

just like two pointer approach but on a BST 

the left pointer will start with leftmost element and right pointer 
with the largest element we check the sum of left and right pointer and 
move the pointers accordingly

*/ 

class BSTIterator {
    bool reverse=true;
    stack<TreeNode*> st;
    
    public:
      
    BSTIterator(TreeNode* root,bool isreverse){
         
        reverse = isreverse;
        pushAll(root);
    }
    //psuh the next value
    int next(){
        TreeNode* topNode = st.top();
        st.pop();
        if(reverse)
            pushAll(topNode->left);
        else
            pushAll(topNode->right);
        
        return topNode->val;
    }
    //if the tree has been fully traversed or not
    bool hasNext()
    {
        return !st.empty();
    }
    //push the values to the stack 
    void pushAll(TreeNode* node)
    {
        while(node)
        {
            st.push(node);
            if(reverse)
                node=node->right;
            else
                node=node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator l (root,false); //starts from the left
        BSTIterator r (root,right); //starts from the right
        
        int i =l.next();
        int j = r.next();
        
        while(i<j)
        {   
            int x=i+j;
            if(x==k)
                return true;
            else if(x<k)
                i=l.next();
            else
                j=r.next();
                
        }
        
        return false;
    }
};
  ```
</div>
