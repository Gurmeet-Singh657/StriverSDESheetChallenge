#include<bits/stdc++.h>
using namespace std;
void Subsets(int last,vector<int>& arr,vector<vector<int>>& ans,vector<int>& currans)
{
    ans.push_back(currans);
    for(int i=last;i<arr.size();i++)
    {
        if(i!=last && arr[i]==arr[i-1]) continue;
        currans.push_back(arr[i]);
        Subsets(i+1,arr,ans,currans);
        currans.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> currans;
    sort(arr.begin(),arr.end());
    Subsets(0,arr,ans,currans);
    return ans;
}