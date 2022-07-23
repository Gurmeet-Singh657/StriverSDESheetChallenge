// if duplicates were not allowed -> this is bst solution
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    int leftcount;
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
        leftcount=0;
    }
};
Node* Insert(int ele,Node* root)
{
    if(root==NULL)
        return new Node(ele);
    if(ele<root->data)
    {
        root->left=Insert(ele,root->left);
        root->leftcount++;
    }
    else
    {
        root->right=Insert(ele,root->right);
    }
    return root;
}
int kthsmallest(int ele,Node* root)
{
    if(root->leftcount+1==ele)
        return root->data;
    else if(root->leftcount+1<ele)
        return kthsmallest(ele-root->leftcount-1,root->right);
    else
        return kthsmallest(root->leftcount,root->left);
}
vector<int> findMedian(vector<int> &arr, int n){
	int size=0;
    vector<int> ans;
    Node* root=NULL;
    for(int i=0;i<n;i++)
    {
        size++;
        root=Insert(arr[i],root);
        if(size%2!=0)
        {
            ans.push_back(kthsmallest(size/2+1,root));
        }
        else
        {
            int median=(kthsmallest(size/2,root)+kthsmallest(size/2+1,root))/2;
            ans.push_back(median);
        }
    }
    return ans;
}
// heap solution
#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    maxheap.push(arr[0]);
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(maxheap.size()==minheap.size())
        {
            if(arr[i]>maxheap.top())
            {
                minheap.push(arr[i]);
                maxheap.push(minheap.top());
                minheap.pop();
            }
            else
            {
                maxheap.push(arr[i]);
            }
            ans.push_back(maxheap.top());
        }
        else
        {
            if(arr[i]>maxheap.top())
            {
                minheap.push(arr[i]);
            }
            else
            {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(arr[i]);
            }
            ans.push_back((maxheap.top()+minheap.top())/2);
        }    
    }
    return ans;
}


