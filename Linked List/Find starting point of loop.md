<h2>Find Starting point of a Loop</h2>
<h3>Easy</h3><hr>
<div><p>
  Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 
</p>


[Problem Link](https://leetcode.com/problems/linked-list-cycle-ii/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [3,2,0,-4], pos = 1
     
<strong>Output:</strong> tail connects to node index 1
<strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the second node. 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. Read the notebook
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
    ListNode *detectCycle(ListNode *head) {
        
        /* Approach 1
         Store every node in map
         The first node that already existed in hashmap is the starting point
         Time => O(n) ,  Space => O(n) 
        */
        
        //optimal Approch with Constant Space
        
    ListNode* fast = head;
    ListNode* slow = head;
    if(!head || !head->next)
        return NULL;
    
    while(fast && fast->next)
    {   
        slow = slow->next;
        fast=fast->next->next;   
        if(fast==slow)
          break;
    }
        
    fast=head;
        
    while(slow)
    {
        if(fast==slow)
          return slow;
        fast=fast->next;
        slow=slow->next;  
    }
    return NULL;
    }
};
  ```
</div>
