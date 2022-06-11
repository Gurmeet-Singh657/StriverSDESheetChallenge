#include <bits/stdc++.h> 
using namespace std;
// ****************************************************************

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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *prev=NULL;
    while(head!=NULL)
    {
        LinkedListNode<int> *ahead=head->next;
        head->next=prev;
        prev=head;
        head=ahead;
    }
    return prev;
}