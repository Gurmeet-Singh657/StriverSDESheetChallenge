#include<bits/stdc++.h>
using namespace std;
int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int low=0,high=arr.size()-2;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==arr[mid^1]) // even -> ahead odd and odd -> behind even
            // this is left half
            low=mid+1;
        else
            high=mid-1;
    }
    return arr[low];
}
