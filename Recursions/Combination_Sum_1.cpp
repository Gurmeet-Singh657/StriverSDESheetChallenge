#include<bits/stdc++.h>
using namespace std;
void findCombinations(vector<int>& arr,int ind,int k,vector<int>& currans,vector<vector<int>>& ans)
{
     if(ind==arr.size())
     {
         if(k==0)
             ans.push_back(currans);
         return;
     }
        currans.push_back(arr[ind]);
        findCombinations(arr,ind+1,k-arr[ind],currans,ans);
        currans.pop_back();
    findCombinations(arr,ind+1,k,currans,ans);
        
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> currans;
    vector<vector<int>> ans;
    findCombinations(arr,0,k,currans,ans);
    return ans;
}