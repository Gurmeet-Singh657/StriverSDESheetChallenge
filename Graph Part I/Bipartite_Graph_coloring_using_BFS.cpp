#include<bits/stdc++.h>
using namespace std;
bool BFS(int src,int color[],vector<vector<int>>& adj)
{
    queue<int> q;
    q.push(src);
    color[src]=0; // color 0 is given to 0th node
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto it:adj[curr])
        {
            if(color[it]==-1) // if no color is assigned
            {
                color[it]=1-color[curr];
                q.push(it);
            }
            else if(color[it]==color[curr])
                return false;
        }
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
            if(!BFS(i,color,adj))
            {
                return false;
            }
        }
    }
    return true;
}