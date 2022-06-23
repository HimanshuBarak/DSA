``` c++
bool detectLoop(Node* head)
    {
        //floyd moore algorithm
        //you can also rename them as fast and slow  pointer
        Node* tortoise=head;
        Node* hare = head;
         //we have to ensure that NULL->next should never happen ,hence hare->next is used
        while( hare && hare->next)
        {   
            hare=hare->next->next; //moves by 2 nodes 
           
            tortoise=tortoise->next; // moves by one node
            if(tortoise==hare)
               return 1;
             
        }
        
        return 0;
    }
```
