#include<bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>>& adj,bool visited[],stack<int>& st,int src)
{
    visited[src]=true;
    for(auto it:adj[src])
    {
        if(!visited[it])
            DFS(adj,visited,st,it);
    }
    st.push(src);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    stack<int> st;
    vector<int> ans;
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    bool visited[v]={0};
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        DFS(adj,visited,st,i);
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}