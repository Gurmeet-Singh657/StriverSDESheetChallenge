#include <bits/stdc++.h> 
using namespace std;
long long merge(long long * arr,int low,int mid,int high)
{
    long long invcount=0;
    int n=mid;
    int m=high;
    int i=low,j=mid+1;
    long long temp[high-low+1];
    int k=0;
    while(i<=n && j<=m)
    {
        if(arr[i]>arr[j])
        {
            temp[k]=arr[j];
            invcount+=(n+1-i);
            k++;
            j++;
        }
        else
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
    }
    while(i<=n)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=m)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++)
        arr[i]=temp[i-low];
    return invcount;
}
long long mergesort(long long * arr,int low,int high)
{
    if(low>=high)
        return 0;
    int mid=(low+high)/2;
    long long invcount=0;
    invcount+=mergesort(arr,low,mid);
    invcount+=mergesort(arr,mid+1,high);
    invcount+=merge(arr,low,mid,high);
    return invcount;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergesort(arr,0,n-1);
}