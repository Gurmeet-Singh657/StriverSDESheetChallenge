#include <bits/stdc++.h> 
// /****************************************************************

    // Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

// *****************************************************************/
LinkedListNode<int>* Reverse(LinkedListNode<int>* node)
{
    LinkedListNode<int>* prev=NULL;
    while(node!=NULL)
    {
        LinkedListNode<int>* ahead=node->next;
        node->next=prev;
        prev=node;
        node=ahead;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL) return true;
    
    LinkedListNode<int>* fast=head,*slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=Reverse(slow->next);
    slow=slow->next;
    fast=head;
    while(slow!=NULL)
    {
        if(fast->data!=slow->data)
            return false;
        slow=slow->next;
        fast=fast->next;
    }
    return true;

}