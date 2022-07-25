#include<bits/stdc++.h>
using namespace std;
int findparent(int u,vector<int>& parent)
{
    if(parent[u]==u)
        return u;
    return parent[u]=findparent(parent[u],parent);
}
void Union(int u,int v,vector<int>& parent,vector<int>& rank)
{
    u=findparent(u,parent);
    v=findparent(v,parent);
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
    }
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}
bool cmp(pair<pair<int,int>,int>& p1,pair<pair<int,int>,int>& p2)
{
    return p1.second<p2.second;
}
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<pair<int,int>,int>> ans;
    vector<int> parent(n+1);
    vector<int> rank(n+1);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
    sort(g.begin(),g.end(),cmp);
    for(int i=0;i<g.size();i++)
    {
        int u=g[i].first.first;
        int v=g[i].first.second;
        int wt=g[i].second;
        if(findparent(u,parent)!=findparent(v,parent))
        {
            Union(u,v,parent,rank);
            ans.push_back({{u,v},wt});
        }
    }
    return ans;
}


// Finding the Weight
#include<bits/stdc++.h>
using namespace std;
int findparent(int u,vector<int>& parent)
{
    if(parent[u]==u)
        return u;
    return parent[u]=findparent(parent[u],parent);
}
void Union(int u,int v,vector<int>& parent,vector<int>& rank)
{
    u=findparent(u,parent);
    v=findparent(v,parent);
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
    }
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}
bool cmp(vector<int>& p1,vector<int>& p2)
{
    return p1[2]<p2[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &g) {
    int ans=0;
    vector<int> parent(n+1);
    vector<int> rank(n+1);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
    sort(g.begin(),g.end(),cmp);
    for(int i=0;i<g.size();i++)
    {
        int u=g[i][0];
        int v=g[i][1];
        int wt=g[i][2];
        if(findparent(u,parent)!=findparent(v,parent))
        {
            Union(u,v,parent,rank);
            ans+=wt;
        }
    }
    return ans;
}