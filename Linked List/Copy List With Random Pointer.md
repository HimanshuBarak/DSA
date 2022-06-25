<h2>Copy List With Random Pointer</h2>
<h3> Medium</h3><hr>
<div><p>
  
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.
 
</p>


[Problem Link](https://leetcode.com/problems/copy-list-with-random-pointer/)

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
<strong>Time:</strong> O(3N)
  
<strong>Space:</strong> O(1)
  <h2> Algorithm </h2>
 <pre>
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        
        //okay the optimal approach is kinda tricky but its actually quite simple
        //there are 3 major steps
        if(!head)
           return NULL;
        //1: Create a copy of each node and place it next to the original node
        Node* curr=head;
        Node* next;
        while(curr)
        {
            next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next=next;
            curr=next;
        }
        
        //2. Copy the random pointers from the original list
        curr=head;
        while(curr){
            if(curr->random) //if random is not NULL
            curr->next->random = curr->random->next;
            curr=curr->next->next;
        }
        //separate out both copied list and original list
        Node* copyhead=head->next;
        Node* copy = copyhead;
        curr=head;
        while(copy->next){
            next= copy->next;
            copy->next = copy->next->next;
            curr->next=next;
            copy=copy->next;
            curr=curr->next;
        }
        curr->next=copy->next;
        return copyhead;
    }
};
  ```
</div>
