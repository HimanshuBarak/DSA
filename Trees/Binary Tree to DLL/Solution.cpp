class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        
        stack<Node*> s;
        Node *start =NULL;
        Node *curr =root;
        Node* dll =NULL;
        
        while(!s.empty() || curr!=NULL)
        {  
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
             s.pop(); 
            
            if(!start)
            {
                start =curr;
                dll=curr;
                start->left=NULL;
                dll->left=NULL;
               
            }
            else
            {
                dll->right=curr;
                curr->left=dll;
                dll=dll->right;
                
            }
            
            curr=curr->right;
            
           
        }
         
        return start;
    }
};
