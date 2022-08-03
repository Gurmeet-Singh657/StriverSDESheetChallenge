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

// Optimised Version
vector<int> answer(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pair<int,pair<int,int>>> pq;
    vector<int> ans;
    int n=A.size();
    set<pair<int,int>> st;
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});
    st.insert({n-1,n-1});
    while(C--)
    {
        auto p=pq.top();
        pq.pop();
        int sum=p.first;
        int i=p.second.first;
        int j=p.second.second;
        
        ans.push_back(sum);
        
        // Explore two combinations possible
        sum=A[i-1]+B[j];
        if(st.find({i-1,j})==st.end())
        {
            pq.push({sum,{i-1,j}});
            st.insert({i-1,j});
        }
        sum=A[i]+B[j-1];
        if(st.find({i,j-1})==st.end())
        {
            pq.push({sum,{i,j-1}});
            st.insert({i,j-1});
        }
    }
    return ans;
}
