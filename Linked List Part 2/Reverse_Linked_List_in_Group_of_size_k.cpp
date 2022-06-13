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
Node* getreverse(Node* head,int i,int n,int b[])
{
    if(i==n) return head;
    if(b[i]==0) return getreverse(head,i+1,n,b);
    int count=0;
    Node* prev=NULL;
    Node* curr=head;
    Node* ahead=NULL;
    while(count<b[i] && curr!=NULL)
    {
        ahead=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ahead;
        count++;
    }
    if(curr!=NULL)
        head->next=getreverse(curr,i+1,n,b);
    return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    return getreverse(head,0,n,b);
}