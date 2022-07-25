#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<pair<int,int>>> adj(vertices);
    for(int i=0;i<vec.size();i++)
    {
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++)
        dist[i]=INT_MAX;
    dist[0]=0;
    while(!pq.empty())
    {
        auto curr=pq.top();
        pq.pop();
        int dis=curr.first;
        int node=curr.second;
        for(auto it:adj[node])
        {
            int adjnode=it.first;
            int adjdist=it.second;
            if(dis+adjdist<dist[adjnode])
            {
                dist[adjnode]=dis+adjdist;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    return dist;
}
