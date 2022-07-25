#include<bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int> ans;
    while(!q.empty())
    {
        int curr=q.front();
        ans.push_back(curr);
        q.pop();
        for(auto it:adj[curr])
        {
            indegree[it]--; 
            if(indegree[it]==0) // means now no one can direct them so it should be taken now
                q.push(it);
        }
    }
    return ans;
}