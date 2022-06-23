#include<bits/stdc++.h>
using namespace std;
class help
{
    public:
    int value;
    int i;
    int j;
    help(int val,int in,int jn)
    {
        value=val;
        i=in;
        j=jn;
    }
};
struct Mycmp
{
    bool operator()(help& h1,help& h2)
    {
        return h1.value>h2.value;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> res;
    priority_queue<help,vector<help>,Mycmp> pq;
    for(int i=0;i<kArrays.size();i++)
    {
        help h({kArrays[i][0],i,0});
        pq.push(h);
    }
    while(!pq.empty())
    {
        help h=pq.top();
        pq.pop();
        res.push_back(h.value);
        int curri=h.i;
        int currj=h.j;
        if(currj+1<kArrays[curri].size())
        {
            help h({kArrays[curri][currj+1],curri,currj+1});
            pq.push(h);
        }
        
    }
    return res;
}
