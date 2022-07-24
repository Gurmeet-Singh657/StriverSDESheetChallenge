#include<bits/stdc++.h>
struct Node
{
    Node* links[2];
    bool containskey(int val)
    {
        return links[val]!=NULL;
    }
    Node* get(int val)
    {
        return links[val];
    }
    void put(int val,Node* node)
    {
        links[val]=node;
    }
};
class Trie
{
    public:
    Node* root;
    Trie()
    {
        root=new Node();
    }
    void Insert(int ele)
    {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int currbit=(ele>>i) & 1;
            if(!node->containskey(currbit))
            {
                node->put(currbit,new Node());
            }
            node=node->get(currbit);
        }
    }
    int search(int ele)
    {
        Node* node=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int currbit=(ele>>i) & 1;
            if(!node->containskey(1-currbit))
            {
                node=node->get(currbit);
            }
            else
            {
                node=node->get(1-currbit);
                ans=ans | (1<<i);
            }
        }
        return ans;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<queries.size();i++)
    {
        v.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(v.begin(),v.end());
    vector<int> ans(queries.size());
    int j=0;
    Trie trie;
    for(int i=0;i<v.size();i++)
    {
        int xi=v[i].second.first;
        int ai=v[i].first;
        while(j<arr.size() && arr[j]<=ai)
        {
            trie.Insert(arr[j]);
            j++;
        }
        if(j==0)
            ans[v[i].second.second]=-1;
        else
            ans[v[i].second.second]=trie.search(xi);
    }
    return ans;
}