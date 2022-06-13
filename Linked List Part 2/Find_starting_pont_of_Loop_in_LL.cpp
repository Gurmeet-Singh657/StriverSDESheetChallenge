#include <bits/stdc++.h> 
// /****************************************************************

    // Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

// *****************************************************************/

Node *firstNode(Node *head)
{
	//    Write your code here.
    if(head==NULL || head->next==NULL) return NULL;
    
    Node* fast=head,*slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            fast=head;
            while(fast!=slow)
            {
                fast=fast->next;
                slow=slow->next;
            }
            return fast;
        }
    }
    return NULL;
}