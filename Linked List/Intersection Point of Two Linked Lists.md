<h2>Intersection of Two Linked Lists</h2>
<h3>Easy</h3><hr>
<div><p>
  Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

 
</p>


[Problem Link](https://leetcode.com/problems/intersection-of-two-linked-lists/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
<strong>Output:</strong> Intersected at '8' 
<strong>Explanation:</strong> The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(m+n)
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. If the lists do not intersect, then both p1 and p2 pointers will finish walking l1 and l2 together and reach NULL.
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         
        /*
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        int cnt1=0,cnt2=0;
        //finding lengths of both the lists
        while(curr1)
        {
            curr1=curr1->next; cnt1++;
        }
        while(curr2){
            curr2 = curr2->next; cnt2++;
        }
        curr1=cnt1>cnt2?headA:headB; //pointer to the larger  one
        curr2=cnt1>cnt2?headB:headA; //pointer the smaller one 
        int k=abs(cnt1-cnt2);
        
        int i=0;
        while(i<k){
            curr1=curr1->next; i++;
        }
            
        //whenever the pointers are equal they are equal
        //imp => pointers are equal not the values 
        while(curr1 && curr2)
        {
            if(curr1==curr2)
                return curr1;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        return NULL;
        */
        //TWO POINTER APPROACH
        if(headA==NULL ||headB==NULL)
            return NULL;
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        
        while(curr1!=curr2)
        {
            curr1= curr1==NULL?headB:curr1->next;
            curr2 = curr2==NULL?headA:curr2->next;
           //both will be null incase of there is no intersection
        }
        return curr1;
    }
};
  ```
</div>
