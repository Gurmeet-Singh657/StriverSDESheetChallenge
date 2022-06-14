#include <bits/stdc++.h> 
// /*************************************************************

    // Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

// *************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head==NULL) return NULL;
    LinkedListNode<int>* curr=head;
    while(head!=NULL)
    {
        LinkedListNode<int>* ahead=head->next;
        head->next=new LinkedListNode<int>(head->data);
        head->next->next=ahead;
        head=ahead;
    }
    LinkedListNode<int>* temp=curr;
    while(temp!=NULL)
    {
        temp->next->random=temp->random?temp->random->next:NULL;
        temp=temp->next->next;
    }
    LinkedListNode<int>* currhead=curr,* newhead=curr->next;
    LinkedListNode<int>* head2=newhead;
    while(currhead)
    {
        currhead->next=currhead->next->next;
        newhead->next=(newhead->next?newhead->next->next:NULL);
        currhead=currhead->next;
        newhead=newhead->next;
    }
    return head2;
}
