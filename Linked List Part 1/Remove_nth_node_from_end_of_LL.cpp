#include <bits/stdc++.h> 
using namespace std;
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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(head==NULL  || K==0) return head;
    LinkedListNode<int>* dummynode=new LinkedListNode<int>(-1);
    LinkedListNode<int>* slow, *fast;
    slow=fast=dummynode;
    dummynode->next=head;
    
    while(K!=0)
    {
        fast=fast->next;
        K--;
    }
    while(fast->next!=NULL)
    {    
        fast=fast->next;
        slow=slow->next;
    }
    LinkedListNode<int>* temp=slow->next;
    slow->next=slow->next->next;
    delete temp;
    return dummynode->next;
    
}