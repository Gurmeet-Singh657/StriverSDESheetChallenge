#include<bits/stdc++.h>
using namespace std;
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++)
        mp[arr[i]]++;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(pq.size()<k)
        pq.push({it->second,it->first});
        
        else if(pq.top().first<it->second)
        {
            pq.pop();
            pq.push({it->second,it->first});
        }
    }
    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}