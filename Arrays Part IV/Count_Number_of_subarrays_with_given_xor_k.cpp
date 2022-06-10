#include <bits/stdc++.h> 
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int currxor=0;
    int count=0;
    // prefixxor count
    map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        currxor=currxor^arr[i];
        if(currxor==x)
            count++;
        if(mp.find(currxor^x)!=mp.end())
        count+=mp[currxor^x];
        
        mp[currxor]++;
    }
    return count;
}