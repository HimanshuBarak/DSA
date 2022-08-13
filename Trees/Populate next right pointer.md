<h2>Populate next Right Pointer</h2>
<h3>Medium</h3><hr>
<div><p>
  
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
 
</p>


[Problem Link](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> root = [1,2,3,4,5,6,7]
<strong>Output:</strong> [1,#,2,3,#,4,5,6,7,#]
<strong>Explanation:</strong> Given the above perfect binary tree (Figure A),
your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = []
     
<strong>Output:</strong> []
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
    
   /**
   If you notice carefully we need to do 2 things
   connect left and right children
   connect left and right subtree 
   
   **/
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        
        Node* curr=root;
        Node* temp = NULL;
        while(curr->left)
        {
            temp=curr;
            while(temp){
              temp->left->next = temp->right; //connect adajacent children 
            if(temp->next)  //connect adajacent subtrees
                temp->right->enxt = temp->next->left;     
             temp=temp->next;   
            }
           
           curr = curr->left; 
        }  
        return root;
    }
};
  ```
</div>
