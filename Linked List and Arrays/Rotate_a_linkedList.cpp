#include <bits/stdc++.h> 
// /********************************

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

// ********************************/


Node *rotate(Node *head, int k) {
     // Write your code here.
    if(head==NULL || head->next==NULL || k==0) return head;
    
   int len=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    k=k%len;
    if(k==0) return head;
    k=len-k;
    temp=head;
    while(k>1)
    {
        temp=temp->next;
        k--;
    }
    Node* temphead=temp->next;
    temp->next=NULL;
    Node* curr=temphead;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=head;
    return temphead;
}