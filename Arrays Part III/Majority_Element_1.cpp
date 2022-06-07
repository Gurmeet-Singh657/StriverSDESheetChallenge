#include <bits/stdc++.h> 
using namespace std;
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    int ele;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(count==0)
            ele=arr[i];
        if(ele==arr[i])
            count++;
        else
            count--;
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(ele==arr[i])
            count++;
    }
    return count>n/2?ele:-1;
}