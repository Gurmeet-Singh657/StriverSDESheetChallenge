#include <bits/stdc++.h>
using namespace std;
int mergesort(vector<int>& arr,int low,int mid,int high)
{
    vector<int> temp;
    int count=0;
    int i=low,j=mid+1;
    // do this work before sorting
    for(int i=low;i<=mid;i++)
    {
        while(j<=high && arr[i]>2*arr[j])
        {
            j++;
        }
        count+=(j-mid-1);
    }
    // -------------------
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(arr[i]>arr[j])
        {
            temp.push_back(arr[j]);
            j++;
        }
        else
        {
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
    return count;
}
int merge(vector<int>& arr,int low,int high)
{
    if(low>=high)
        return 0;
    int reversepaircount=0;
    int mid=(low+high)/2;
    reversepaircount+=merge(arr,low,mid);
    reversepaircount+=merge(arr,mid+1,high);
    reversepaircount+=mergesort(arr,low,mid,high);
    return reversepaircount;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
    return merge(arr,0,n-1);
}