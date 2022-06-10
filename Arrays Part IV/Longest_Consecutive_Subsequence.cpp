#include <bits/stdc++.h> 
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> st;
    for(int i=0;i<arr.size();i++)
    {
        st.insert(arr[i]);
    }
    int maxi=0;
    for(int i=0;i<arr.size();i++)
    {
        if(st.find(arr[i]-1)==st.end()) // This means it is the starting point
        {
            int ele=arr[i];
            int count=1;
            while(st.find(ele+1)!=st.end())
            {
                count++;
                ele=ele+1;
            }
            maxi=max(maxi,count);
        }
    }
    return maxi;
}