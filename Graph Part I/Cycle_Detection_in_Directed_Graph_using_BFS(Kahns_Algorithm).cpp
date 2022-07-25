#include<bits/stdc++.h>
using namespace std;
int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
    vector<vector<int>> adj(v+1);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<int> indegree(v+1,0);
    for(int i=1;i<=v;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=v;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    int count=0;
    while(!q.empty())
    {
        int curr=q.front();
        count++;
        q.pop();
        for(auto it:adj[curr])
        {
            indegree[it]--; 
            if(indegree[it]==0) // means now no one can direct them so it should be taken now
                q.push(it);
        }
    }
    return v!=count;
}