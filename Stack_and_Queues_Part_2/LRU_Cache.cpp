#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k,int v)
    {
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache
{
    int cap;
    int size;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;
public:
    LRUCache(int capacity)
    {
        size=0;
        cap=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    void deleteNode(Node* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void addToHead(Node* node)
    {
        head->next->prev=node;
        node->next=head->next;
        head->next=node;
        node->prev=head;
    }
    int get(int key)
    {
        if(!mp.empty() && mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            deleteNode(node);
            addToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(mp[key]!=NULL)
        {
            Node* newnode=mp[key];
            deleteNode(newnode);
            newnode->value=value;
            addToHead(newnode);
        }
        else
        {
            Node* newnode=new Node(key,value);
            mp[key]=newnode;
            if(size<cap)
            {
                addToHead(newnode);
                size++;
            }
            else
            {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(newnode);
            }
        }
    }
};
