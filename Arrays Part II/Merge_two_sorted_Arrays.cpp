#include <bits/stdc++.h> 
using namespace std;
// O(n*m) giving TLE
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    // if I want to do the answer in O(1) space
    for(int i=0;i<m;i++)
    {
        if(arr1[i]>arr2[0])
        {
            swap(arr1[i],arr2[0]);
            int j=1;
            int ele=arr2[0];
            while(j<arr2.size() && arr2[j]<ele)
            {
                arr2[j-1]=arr2[j];
                j++;
            }
            arr2[j-1]=ele;
        }
    }
    for(int i=0;i<arr2.size();i++)
        arr1[m+i]=arr2[i];
    return arr1;
}
// O(N)
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int i=m-1,j=n-1,index=m+n-1;
    while(i>=0 && j>=0)
    {
        if(arr1[i]>arr2[j])
        {
            arr1[index]=arr1[i];
            i--;
            index--;
        }
        else
        {
            arr1[index]=arr2[j];
            j--;
            index--;
        }
    }
    while(j>=0)
    {
        arr1[index]=arr2[j];
        index--;
        j--;
    }
    return arr1;
}