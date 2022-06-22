<h2>Add 2 number using a linked list</h2>
<h3>Easy</h3><hr>
<div><p>
  
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
</p>


[Problem Link](https://leetcode.com/problems/add-two-numbers/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> 2--> 4--> 3
                             5-->6 -->4
<strong>Output:</strong> 7-->0-->8
<strong>Explanation:</strong> 342 + 465 = 807
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
  1. Just add lol create a new linked list to store the results and thats pretty much it
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //using some space complexity
        ListNode* head = new ListNode(0);
        ListNode* curr = head; 
        int carry=0,sum=0;
        ListNode* p1=l1; ListNode* p2 = l2;
        
        while(p1 ||p2)
        {   
         sum=0;
         if(p1)
           sum+=p1->val,p1=p1->next;   
         if(p2)
           sum+=p2->val,p2=p2->next; 
         sum+=carry;   
         carry = sum>9?sum/10:0;
         curr->next = new ListNode(sum%10);
         curr=curr->next;
        }
        if(carry>0)
           curr->next  = new ListNode(carry);
        
        return head->next;
    }
};
  ```
</div>
