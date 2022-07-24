#include<bits/stdc++.h>
using namespace std;
bool BFS(int src,bool visited[],vector<vector<int>>& adj)
{
    queue<pair<int,int>> q;
    q.push({src,-1});
    visited[src]=true;
    while(!q.empty())
    {
        auto curr=q.front();
        q.pop();
        int node=curr.first;
        int parent=curr.second;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=true;
                q.push({it,node});
            }
            else if(it!=parent)
            {
                return true;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n+1);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    bool visited[n]={0};
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(BFS(i,visited,adj))
            {
                return "Yes";
            }
        }
    }
    return "No";
}
