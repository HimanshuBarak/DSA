 ```c++
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
          
          if(l1==NULL)
              return l2;
          if(l2==NULL)
              return l1;
        
         //now for the sweet part 
          if(l1->val < l2->val)
          {
              l1->next = mergeTwoLists(l1->next,l2); //this node is selected the next node will be whichever is smaller l1->next or l2 and so on
              return l1;
          }
          else
          {
              l2->next = mergeTwoLists(l1,l2->next);
              return l2;
          }
    }
```
