<h2>Reverse Nodes in K group</h2>
<h3>Hard</h3><hr>
<div><p>
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

 
</p>


[Problem Link](https://leetcode.com/problems/reverse-nodes-in-k-group/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [2,1,4,3,5]
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* before =dummyhead;
        ListNode* after = head;
        ListNode* prev=NULL;
        ListNode* curr=NULL;
        ListNode* next=NULL;
        
        while(true)
        {
            //check if the leftover nodes are less than k if so return head
            ListNode* cursor = after;
            for(int i=0;i<k;i++)
            {
                if(!cursor) return dummyhead->next;
                cursor = cursor->next;
            }
            //reversing within k elements
            prev= before;//before points to reversed last element of the last group
            curr=after; //after always points to first element of this kth group
            for(int i=0;i<k;i++)
            {
                next = curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            before->next= prev; //last element of the group
            after->next =curr;//first elemt points to first element of the next group
            before=after; //first element of group becomes last after reversal
            after=curr; //point to the first element of the next group
        }
    }
};
  ```
</div>
