<h2>Check if a Linked List is Palindrome or Not</h2>
<h3>Easy</h3><hr>
<div><p>
  
Given the head of a singly linked list, return true if it is a palindrome.
 
</p>


[Problem Link](https://leetcode.com/problems/palindrome-linked-list/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> head = [1,2,2,1]
<strong>Output:</strong> true
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
    ListNode* reverseList(ListNode* head) {
        
        //this is pretty simple   
        ListNode* prev = NULL; 
        ListNode* curr =head;
        ListNode* next;
        while(curr)
        {
           next = curr->next;
           curr->next=prev;
           prev = curr;
           head=curr;  //this works because before curr == NULL it will store value of last element
           curr=next;
        } 
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        //finding the middle of the list
        
        if(!head || !head->next)
            return true;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        
        while(fast && fast->next)
        {
           prev=slow;
           slow=slow->next;
           fast=fast->next->next;
        }
       
        prev->next=NULL;
        //fast!=NULL means length of the linked list in odd else its even
        ListNode* curr1= fast!=NULL?slow->next:slow;
        //reverse first half
        ListNode* curr=reverseList(head);
        while(curr)
        {  
            if(curr->val!=curr1->val)
            {
                
                return false;
            }
            
            curr=curr->next;
            curr1=curr1->next;
        }
        
        return true;
    }
};
  ```
</div>
