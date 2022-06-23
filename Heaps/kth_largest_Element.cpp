#include<bits/stdc++.h>
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	priority_queue<int> maxheap; // maxheap for finding kth smallest element
    priority_queue<int,vector<int>,greater<int>> minheap; // minheap for finding kth largest element
    for(int i=0;i<k;i++)
    {
        maxheap.push(arr[i]);
        minheap.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(maxheap.top()>arr[i])
        {
            maxheap.pop();
            maxheap.push(arr[i]);
        }
        if(minheap.top()<arr[i])
        {
            minheap.pop();
            minheap.push(arr[i]);
        }
    }
    return {maxheap.top(),minheap.top()};
}