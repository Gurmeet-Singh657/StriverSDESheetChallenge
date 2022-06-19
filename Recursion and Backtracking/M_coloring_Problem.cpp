#include<bits/stdc++.h>
using namespace std;
bool isSafe(int visited[],vector<int> adj[],int color,int ele)
{
    for(auto it:adj[ele])
    {
        if(visited[it]==color)
            return false;
    }
    return true;
}
bool Colorgraph(int node,vector<int> adj[],int m,int visited[],int n)
{
    if(node==n)
        return true;
    
    for(int i=1;i<=m;i++)
    {
        if(isSafe(visited,adj,i,node))
        {
            visited[node]=i;
            if(Colorgraph(node+1,adj,m,visited,n))
                return true;
            visited[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    vector<int> adj[mat.size()];
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            if(mat[i][j]==1)
                adj[i].push_back(j);
        }
    }
    int visited[mat.size()]={0};
    return Colorgraph(0,adj,m,visited,mat.size())?"YES":"NO";
}