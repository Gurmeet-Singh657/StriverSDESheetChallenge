#include <bits/stdc++.h> 
using namespace std;
// /************************************************************

    // Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

// ************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* head,*temp;
    if(first==NULL) return second;
    if(second==NULL) return first;
    if(first->data<=second->data)
      {  
        head=first;
        temp=first;
        first=first->next;
      }
    else
      {
        head=second;
        temp=second;
        second=second->next;
      }
    while(first!=NULL && second!=NULL)
    {
        if(first->data<=second->data)
        {
            temp->next=first;
            first=first->next;
            temp=temp->next;
        }
        else
        {
            temp->next=second;
            second=second->next;
            temp=temp->next;
        }
    }
    while(first!=NULL)
    {
           temp->next=first;
            first=first->next;
            temp=temp->next;
    }
    while(second!=NULL)
    {
        temp->next=second;
            second=second->next;
            temp=temp->next;
    }
    return head;
}
