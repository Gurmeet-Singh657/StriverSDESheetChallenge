#include<bits/stdc++.h>
using namespace std;
void findMedian(int *arr, int n)
{
    if(n==0)
        return;
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    maxheap.push(arr[0]);
    cout<<arr[0]<<" ";
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
            cout<<maxheap.top()<<" ";
        }
        else // maxheap size is greater than minheap 
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
           cout<<(maxheap.top()+minheap.top())/2<<" ";
        }
    }
}