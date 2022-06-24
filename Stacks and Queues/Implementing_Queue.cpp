#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
class Queue {
public:
    Node* head,*tail;
    int size;
    Queue() {
        head=NULL;
        tail=NULL;
        size=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return head==NULL;
    }

    void enqueue(int data) {
        Node* temp=new Node(data);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            return;
        }
        tail->next=temp;
        tail=temp;
    }

    int dequeue() {
        if(head==NULL)
            return -1;
        int ele=head->data;
        head=head->next;
        if(head==NULL)
            tail=NULL;
        return ele;
    }

    int front() {
        if(head==NULL)
            return -1;
        return head->data;
    }
};