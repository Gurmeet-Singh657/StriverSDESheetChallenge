#include <bits/stdc++.h> 
using namespace std;
long getTrappedWater(long *arr, int n){
    // Write your code here.
    int l=0,r=n-1;
    long res=0;
    long leftmax=0,rightmax=0;
    while(l<=r)
    {
        if(arr[l]<=arr[r])
        {
            if(arr[l]>=leftmax)
                leftmax=arr[l];
            else
                res+=(leftmax-arr[l]);
            l++;
        }
        else
        {
            if(arr[r]>=rightmax)
                rightmax=arr[r];
            else
                res+=(rightmax-arr[r]);
            r--;
        }
    }
    return res;
}