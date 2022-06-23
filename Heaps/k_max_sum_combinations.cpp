#include<bits/stdc++.h>
using namespace std;
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    priority_queue<int,vector<int>,greater<int>> pq; // Minheap
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            int sum=a[i]+b[j];
            if(pq.size()<k)
                pq.push(sum);
            else
            {
                if(pq.top()<sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}