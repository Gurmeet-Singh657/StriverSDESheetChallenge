#include<bits/stdc++.h>
using namespace std;
bool DFS(int src,int parent,bool visited[],vector<vector<int>>& adj)
{
    visited[src]=true;
    for(auto it:adj[src])
    {
        if(!visited[it])
        {
            if(DFS(it,src,visited,adj))
                return true;
        }
        else if(it!=parent)
        {
            return true;
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
            if(DFS(i,-1,visited,adj))
            {
                return "Yes";
            }
        }
    }
    return "No";
}
