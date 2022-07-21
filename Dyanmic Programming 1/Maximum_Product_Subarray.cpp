#include<bits/stdc++.h>
using namespace std;
int maximumProduct(vector<int> &arr, int n)
{
	int maxi=arr[0];
    int mini=arr[0];
    int finalans=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<0)
            swap(maxi,mini);
        maxi=max(maxi*arr[i],arr[i]);
        mini=min(mini*arr[i],arr[i]);
        finalans=max(finalans,maxi);
    }
    return finalans;
}
