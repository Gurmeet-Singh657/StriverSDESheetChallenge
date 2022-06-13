#include <bits/stdc++.h> 
// /****************************************************************

    // Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

// *****************************************************************/
// Merge two linked List
Node* mergeLL(Node* head1,Node* head2)
{
    Node* temp=new Node(-1);
    Node* res=temp;
    while(head1 && head2)
    {
        if(head1->data<=head2->data)
        {
            temp->child=head1;
            head1=head1->child;
            temp=temp->child;
        }
        else
        {
            temp->child=head2;
            head2=head2->child;
            temp=temp->child;
        }
        temp->next=NULL;
    }
    if(head1!=NULL) temp->child=head1;
    else temp->child=head2;
    temp->next=NULL;
    return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head==NULL || head->next==NULL)
        return head;
    
    head->next=flattenLinkedList(head->next);
    
    return mergeLL(head,head->next);

}
