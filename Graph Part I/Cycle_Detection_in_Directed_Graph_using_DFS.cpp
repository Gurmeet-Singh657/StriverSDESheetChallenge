#include<bits/stdc++.h>
using namespace std;
bool DFS(vector<vector<int>>& adj,bool visited[],int src,bool dfsvisited[])
{
    visited[src]=true;
    dfsvisited[src]=true;
    for(auto it:adj[src])
    {
        if(!visited[it])
        {
            if(DFS(adj,visited,it,dfsvisited))
                return true;
        }
        else if(dfsvisited[it])
        {
            return true;
        }
    }
    dfsvisited[src]=false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> adj(n+1);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    bool visited[n]={0};
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool dfsvisited[n]={0};
            if(DFS(adj,visited,i,dfsvisited))
                return 1;
        }   
    }
    return 0;
}