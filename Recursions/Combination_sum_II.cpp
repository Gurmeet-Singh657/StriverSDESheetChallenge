#include<bits/stdc++.h>
using namespace std;
void FindCombinations(int ind,vector<int>& arr,int n,int target,vector<vector<int>>& ans,vector<int>& currans)
{
    if(target==0)
    {
        ans.push_back(currans);
        return;
    }
    if(ind==n)
        return;
    
    for(int i=ind;i<n;i++)
    {
        if(i!=ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break; // there is no use of traversing ahead since our array is sorted
        currans.push_back(arr[i]);
        FindCombinations(i+1,arr,n,target-arr[i],ans,currans);
        currans.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<int> currans;
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
	FindCombinations(0,arr,n,target,ans,currans);
    return ans;
}
