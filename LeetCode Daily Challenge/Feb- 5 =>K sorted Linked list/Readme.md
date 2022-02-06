<h2>Merge K Sorted Linked Lists</h2>
<h3>Hard</h3><hr>
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.


</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>lists = [[1,4,5],[1,3,4],[2,6]]
<strong>Output:</strong> [1,1,2,3,4,4,5,6]
<strong>Explanation:</strong> The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> []
<strong>Output:</strong> []
<strong>Explanation:</strong>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
 

  
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    ListNode* sort(ListNode *l1,ListNode *l2)
    {
        
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        //in case both the linked lists are present
        if(l1->val <l2->val)
        {
            l1->next = sort(l1->next,l2);
            return l1; 
        }
        else
        {
            l2->next = sort(l1,l2->next);
            return l2;
        }  
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
       
        ListNode* res = lists[0];
        
        for(int i=1;i<lists.size();i++)
        {
            res= sort(res,lists[i]);
        }
        return res;
    }
};
  ```
</div>
