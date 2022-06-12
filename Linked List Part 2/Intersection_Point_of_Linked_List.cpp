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

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node* first=firstHead,*second=secondHead;
    while(first!=second)
    {
        first=first==NULL?secondHead:first->next;
        second=second==NULL?firstHead:second->next;
    }
    return first==NULL?-1:first->data;
}