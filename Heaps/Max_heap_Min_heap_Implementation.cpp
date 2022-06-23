#include<bits/stdc++.h>
using namespace std;
void Insert(vector<int>& arr,int element)
{
    arr.push_back(element);
    for(int i=arr.size()-1;i>=0 && arr[(i-1)/2]>arr[i];)
    {
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
void Heapify(int i,vector<int>& arr)
{
    int smallest=i;
    int n=arr.size();
    int lt=(2*i+1);
    int rt=(2*i+2);
    if(lt<n && arr[lt]<arr[smallest])
        smallest=lt;
    if(rt<n && arr[rt]<arr[smallest])
        smallest=rt;
    if(smallest!=i)
    {
        swap(arr[smallest],arr[i]);
        Heapify(smallest,arr);
    }
}
int ExtractMin(vector<int>& arr)
{
    int n=arr.size();
    swap(arr[0],arr[n-1]);
    int ele=arr[n-1];
    arr.pop_back();
    Heapify(0,arr);
    return ele;
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> arr;
    vector<int> ans;
    for(int i=0;i<q.size();i++)
    {
        if(q[i][0]==0)
            Insert(arr,q[i][1]);
        else if(q[i][0]==1)
            ans.push_back(ExtractMin(arr));
    }
    return ans;
}
