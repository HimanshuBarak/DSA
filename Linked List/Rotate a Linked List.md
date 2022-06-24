<h2>Rotate a Linked List</h2>
<h3>Medium</h3><hr>
<div><p>
  Given the head of a linked list, rotate the list to the right by k places.

 

 
</p>


[Problem Link](https://leetcode.com/problems/rotate-list/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [4,5,1,2,3]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [0,1,2], k = 4
     
<strong>Output:</strong> [2,0,1]
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head )
            return head;
        
        ListNode* fast=head;
        int n=1;
        //finding the length of the list
        while(fast->next)
        {
            fast=fast->next;
            n++;
        }
        k=k%n;
        if(!k)
         return head;
        
        fast->next=head;  //list is made circular 
        for(int i=0;i<n-k;i++)
            fast=fast->next;
        
        head=fast->next;
        fast->next=NULL;
        return head;
    }
};
  ```
</div>
