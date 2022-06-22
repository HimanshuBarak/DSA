<h2>Delete a Node in a Linked List</h2>
<h3>Easy</h3><hr>
<div><p>
  Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list. 
</p>


[Problem Link](https://leetcode.com/problems/delete-node-in-a-linked-list/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> head = [4,5,1,9], node = 5
<strong>Output:</strong> [4,1,9]
<strong>Explanation:</strong> You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
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
  1. View discussion in leetcode to understand the O(1) solution
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
       //Naive Approach 
    /*
       ListNode* nextNode = node->next;
        ListNode* curr= node;
        while(nextNode->next)
        {
            curr->val =nextNode->val;
            curr = curr->next;
            nextNode = nextNode->next;
        }
        curr->val =nextNode->val;
            curr->next=NULL;
    */ 
        // O(1) approach
        //basically we copy the next pointer to current one and delete the next pointer
        
        ListNode* nodeNext = node->next;
        *node =*nodeNext;
        
        delete nodeNext;
    }
};
  ```
</div>
