``` c++
// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  //to merge the sorted lists
  Node* mergeLists(Node* l1,Node* l2)
  {
       if(l1==NULL)
        return l2;
       if(l2==NULL)
        return l1;
        
       if(l1->data <l2->data)
       {
           l1->next = mergeLists(l1->next,l2);
           return l1;
       }
       else{
           l2->next = mergeLists(l1,l2->next);
           return l2; 
       }
    }
   //to find the middle of the linked list
   Node* middleNode(Node* head) {
         
         Node* fast = head->next;
         Node* slow = head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    Node* MergeSort(Node* head,Node* tail)
    {   
        
        if(head==NULL || head->next==NULL)
          return head;
          
        if(head==tail)
         {
             Node* temp = new Node(head->data);
             return temp;
         }
          
        Node* mid=middleNode(head);
        Node* k=mid->next;
        mid->next=NULL;         ///// why do we need this 
        //sorts the left half
        Node* a=MergeSort(head,mid);
        //sorts the right half
        Node* b=MergeSort(k,tail);
        Node* st =mergeLists(a,b);
        
        return st;
    }
    
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
          
          Node* temp=head;
          //finding the tail
          while(temp->next!=NULL)
          {
             temp=temp->next; 
              
          }
       
          
       return MergeSort(head,temp); //passing the head and tail of the linked list;
        
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
```
