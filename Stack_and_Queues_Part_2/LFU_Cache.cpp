#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    int value;
    int cnt;
    Node* prev;
    Node* next;
    Node(int k,int val)
    {
        key=k;
        value=val;
        cnt=1;
        prev=NULL;
        next=NULL;
    }
};
class List
{ 
    public:
    Node* head, *tail;
     int size;
    List()
    {
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addToHead(Node* node)
    {
        node->next=head->next;
        node->prev=head;
        head->next=node;
        node->next->prev=node;
        size++;
    }
    void deleteNode(Node* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
        size--;
    }
};
class LFUCache
{
    map<int,Node*> mp;
    map<int,List*> freqListMap;
    int cap;
    int size;
    int minfreq;
    public:
    LFUCache(int capacity)
    {
        cap=capacity;
        size=0;
        minfreq=0;
    }
    void updateFreqListMap(Node* node)
    {
        freqListMap[node->cnt]->deleteNode(node);
        if(node->cnt==minfreq && freqListMap[node->cnt]->size==0)
            minfreq++;
        
        List* nextHigherlist=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end())
            nextHigherlist=freqListMap[node->cnt+1];
        node->cnt+=1;
        nextHigherlist->addToHead(node);
        freqListMap[node->cnt]=nextHigherlist;
    }
    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            int val=node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
         if(cap==0)
             return;
        
        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            node->value=value;
            updateFreqListMap(node);
        }
        else
        {
            if(size==cap)
            {
                mp.erase(freqListMap[minfreq]->tail->prev->key);
                freqListMap[minfreq]->deleteNode(freqListMap[minfreq]->tail->prev);
                size--;
            }
            size++;
            List* nextHigherList=new List();
            if(freqListMap.find(1)!=freqListMap.end())
                nextHigherList=freqListMap[1];
            Node* newnode=new Node(key,value);
            nextHigherList->addToHead(newnode);
            mp[key]=newnode;
            minfreq=1;
            freqListMap[1]=nextHigherList;
        }
    }
};
