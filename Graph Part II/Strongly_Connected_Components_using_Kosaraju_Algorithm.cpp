#include<bits/stdc++.h>
using namespace std;
void DFS(int src,vector<vector<int>>& adj,bool visited[],stack<int>& st)
{
    visited[src]=true;
    for(auto it:adj[src])
    {
        if(!visited[it])
            DFS(it,adj,visited,st);
    }
    st.push(src);
}
void revDFS(int src,vector<vector<int>>& adj,bool visited[],vector<int>& ans)
{
    visited[src]=true;
    ans.push_back(src);
    for(auto it:adj[src])
    {
        if(!visited[it])
            revDFS(it,adj,visited,ans);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    // Maintaining the topo sort
    stack<int> st;
    bool visited[n]={0};
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            DFS(i,adj,visited,st);
    }
    // Transpose the graph
    vector<vector<int>> reverseadj(n);
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        for(auto it:adj[i])
        {
            reverseadj[it].push_back(i);
        }
    }
    // Do DFS 
    vector<vector<int>> finalans;
    while(!st.empty())
    {
        if(!visited[st.top()])
        {
            vector<int> ans;
            revDFS(st.top(),reverseadj,visited,ans);
            sort(ans.begin(),ans.end());
            finalans.push_back(ans);
        }
        st.pop();
    }
    return finalans;
}