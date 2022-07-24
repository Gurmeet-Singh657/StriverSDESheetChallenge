#include<bits/stdc++.h>
using namespace std;
bool DFS(int src,int color[],vector<vector<int>>& adj)
{
    if(color[src]==-1)
    color[src]=0;
    for(auto it:adj[src])
    {
        if(color[it]==-1)
        {
            color[it]=1-color[src];
            if(!DFS(it,color,adj))
                return false;
        }
        else if(color[it]==color[src])
            return false;
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n=edges.size();
    vector<vector<int>> adj(n);
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(edges[i][j]==1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int color[n];
    for(int i=0;i<n;i++)
        color[i]=-1;
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!DFS(i,color,adj))
            {
                return false;
            }
        }
    }
    return true;
}