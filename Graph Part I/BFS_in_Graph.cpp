#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(int src,bool visited[],vector<vector<int>>& adj)
{
    queue<int> q;
    q.push(src);
    visited[src]=true;
    vector<int> ans;
    ans.push_back(src);
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto it:adj[curr])
        {
            if(!visited[it])
            {
                q.push(it);
                ans.push_back(it);
                visited[it]=true;
            }
        }
    }
    return ans;
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>> adj(vertex);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    for(int i=0;i<vertex;i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }
    bool visited[vertex]={0};
    vector<int> ans;
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
        {
            vector<int> curr=BFS(i,visited,adj);
            ans.insert(ans.end(),curr.begin(),curr.end());
        }
    }
    return ans;
}
