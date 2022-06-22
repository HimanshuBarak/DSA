<h2>Remove Nth node from a linked list</h2>
<h3></h3><hr>
<div><p>
  

 
</p>


[Problem Link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> head = [1,2,3,4,5], n = 2
<strong>Output:</strong> [1,2,3,5]
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
    ListNode* removeNthFromEnd(ListNode* head, int n) { 
       /*
        int cnt=0;
        ListNode* prev=head;
        ListNode* curr=head;
        while(curr)
        {
            cnt++;
            curr=curr->next;
        }   
        int k=cnt-n;
        if(k==0)  //if element to be deleted is the head of the node
            return head->next;  
        curr=head->next;      
        cnt=1;
        while(k!=cnt)
        {
            prev=curr; cnt++;
            curr=curr->next;  
        }
         prev->next=curr->next; //hogya delete
        return head;
        */
       
        /*
        Initally point both fast and slow to a false head 
        Algo is simple
        Move fast pointer to n places before hand
        After that move fast and slow together when fast reaches nULL slow
        will be at the place of deletion of the array
        */
        ListNode* newhead = new ListNode(); //dummyhead
        newhead->next=head;
        ListNode* fast=newhead;
        ListNode* slow=newhead;
        int i=0;
        while(i<n){
            fast=fast->next;
            i++;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        //slow is at the pointing to node that is before the node to be deleted
        slow->next=slow->next->next; //this works even when head is to be del
//because even if slow doesnt even move once it points to the element ahead of head
        return newhead->next;
    }
};
  ```
</div>
