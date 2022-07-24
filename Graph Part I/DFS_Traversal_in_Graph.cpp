#include<bits/stdc++.h>
using namespace std;
void DFS(bool visited[],vector<vector<int>>& adj,int src,vector<int>& curr)
{
    visited[src]=true;
    curr.push_back(src);
    for(auto it:adj[src])
    {
        if(!visited[it])
        {
            DFS(visited,adj,it,curr);
        }
    }
    
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> ans;
    bool visited[V]={0};
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            vector<int> curr;
            DFS(visited,adj,i,curr);
            sort(curr.begin(),curr.end());
            ans.push_back(curr);
        }
    }
    return ans;
}