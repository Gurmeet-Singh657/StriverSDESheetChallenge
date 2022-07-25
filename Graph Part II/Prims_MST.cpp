#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<g.size();i++)
    {
        adj[g[i].first.first].push_back({g[i].first.second,g[i].second});
        adj[g[i].first.second].push_back({g[i].first.first,g[i].second});
    }
    vector<int> key(n+1);
    vector<int> parent(n+1);
    vector<bool> MST(n+1);
    for(int i=0;i<=n;i++)
    {
        key[i]=INT_MAX;
        parent[i]=-1;
        MST[i]=false;
    }
    key[1]=0;
    for(int i=1;i<n;i++)
    {
        int mini=INT_MAX;
        int minindex=-1;
        for(int j=1;j<=n;j++)
        {
            if(!MST[j] && mini>key[j])
            {
                mini=key[j];
                minindex=j;
            }
        }
        MST[minindex]=true;
        for(auto it:adj[minindex])
        {
            if(!MST[it.first] && key[it.first]>it.second)
            {
                key[it.first]=it.second;
                parent[it.first]=minindex;
            }
        }
    }
    vector<pair<pair<int,int>,int>> ans;
    for(int i=2;i<=n;i++)
    {
        ans.push_back({{i,parent[i]},key[i]});
    }
    return ans;
}

// optimised using Priority Queue
#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<g.size();i++)
    {
        adj[g[i].first.first].push_back({g[i].first.second,g[i].second});
        adj[g[i].first.second].push_back({g[i].first.first,g[i].second});
    }
    vector<int> key(n+1);
    vector<int> parent(n+1);
    vector<bool> MST(n+1);
    for(int i=0;i<=n;i++)
    {
        key[i]=INT_MAX;
        parent[i]=-1;
        MST[i]=false;
    }
    key[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int dis=it.first;
        int minindex=it.second;
        MST[minindex]=true;
        for(auto it:adj[minindex])
        {
            if(!MST[it.first] && key[it.first]>it.second)
            {
                key[it.first]=it.second;
                parent[it.first]=minindex;
                pq.push({it.second,it.first});
            }
        }
    }
    vector<pair<pair<int,int>,int>> ans;
    for(int i=2;i<=n;i++)
    {
        ans.push_back({{i,parent[i]},key[i]});
    }
    return ans;
}


