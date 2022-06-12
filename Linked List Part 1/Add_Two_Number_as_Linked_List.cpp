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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node* dummynode=new Node(-1);
    Node* temp=dummynode;
    int carry=0;
    while(head1!=NULL || head2!=NULL)
    {
        int sum=carry;
        if(head1!=NULL)
        {
            sum+=head1->data;
            head1=head1->next;
        }
        if(head2!=NULL)
        {
            sum+=head2->data;
            head2=head2->next;
        }
        carry=sum/10;
        sum=sum%10;
        temp->next=new Node(sum);
        temp=temp->next;
    }
    if(carry!=0)
        temp->next=new Node(carry);
    return dummynode->next;
}