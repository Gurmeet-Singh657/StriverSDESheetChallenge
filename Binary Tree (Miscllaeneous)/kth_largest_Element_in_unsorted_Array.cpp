#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int size, int k)
{
	priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<arr.size();i++)
    {
        if(pq.size()<k)
        {
            pq.push(arr[i]);
        }
        else
        {
            if(arr[i]>pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }
    return pq.top();
}