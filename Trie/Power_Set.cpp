#include<bits/stdc++.h>
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    sort(v.begin(),v.end());
    int power=(int)pow(2,v.size());
    for(int i=0;i<power;i++)
    {
        vector<int> curr;
        for(int j=0;j<v.size();j++)
        {
            if((i>>j) & 1)
            {
                curr.push_back(v[j]);
            }
        }
        ans.push_back(curr);
    }
    return ans;
}