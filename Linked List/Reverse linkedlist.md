<h3> Reverse a given linked list  </h3>

```c++

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
};


```
