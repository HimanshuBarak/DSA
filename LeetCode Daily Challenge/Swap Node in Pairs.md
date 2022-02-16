<h2>Swap Node in Pairs</h2>
<h3>Medium</h3><hr>
<div><p> Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values 
  in the list's nodes (i.e., only nodes themselves may be changed.)
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> head = [1,2,3,4]
<strong>Output:</strong> [2,1,4,3]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [1]
     
<strong>Output:</strong> [1]
<strong>Explanation:</strong>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
  
  Recursive Approach
  
  Reverse the two nodes and leave next to recursion
  
  Interative Approach is nice
   
   [Dry run as per this approach](https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11331/4ms-Easy-C%2B%2B-Iterative-Solution)
  
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        //reverse 2 nodes at a time and you are done   
        ListNode* temp =head->next;   
        head->next= swapPairs(head->next->next);
         temp->next =head;
        return temp;
        
    }
};
  ```
</div>
