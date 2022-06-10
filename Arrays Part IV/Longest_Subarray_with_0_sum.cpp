#include <bits/stdc++.h> 
using namespace std;
int LongestSubsetWithZeroSum(vector < int > arr) {
    map<int,int> mp;
    int maxi=0;
    int prefixsum=0;
    for(int i=0;i<arr.size();i++)
    {
        prefixsum+=arr[i];
        if(prefixsum==0)
            maxi=i+1;
        if(mp.find(prefixsum)!=mp.end())
            maxi=max(maxi,i-mp[prefixsum]);
        else
            mp.insert({prefixsum,i});
    }
    return maxi;
}