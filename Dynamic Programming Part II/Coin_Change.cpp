#include<bits/stdc++.h>
using namespace std;
// Normal Recursion
// time comp - >> 2^n (exponential) // since every number is accessed more than 1 time or many times
// space comp - >> O(N) (exponential)
int sumofallpossib(vector<int>& arr,int ind,int target)
{
    if(ind==0)
    {
        // if(target%arr[0]==0)
        // return 1;
        // return 0;
        return target%arr[0];
    }
    int nottake=sumofallpossib(arr,ind-1,target);
    int take=0;
    if(arr[ind]<=target)
    take=sumofallpossib(arr,ind,target-arr[ind]);
    return take+nottake;
}
// Memoization
// TC - O(n*t)
// Sc - O(N*t) + O(target) // auxilary stack space included
int sumofallpossib(vector<int>& arr,int ind,int target,vector<vector<int>>& dp)
{
    if(ind==0)
    return target%arr[0];
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notake=sumofallpossib(arr,ind-1,target,dp);
    int take=0;
    if(arr[ind]<=target)
    take=sumofallpossib(arr,ind,target-arr[ind],dp);
    return dp[ind][target]=take + notake;
}
// tabulation
// SC - O(N*T)
// TC - O(N*T)
int sumofallpossib(vector<int>& arr,int n,int target)
{
    vector<vector<int>> dp(arr.size(),vector<int>(target+1,0));
    for(int tar=0;tar<=target;tar++)
    {
        if(tar%arr[0]==0)
        dp[0][tar]=1;
        else
        dp[0][tar]=0;
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int tar=0;tar<=target;tar++)
        {
            int nottake=dp[ind-1][tar];
            int take=0;
            if(arr[ind]<=tar)
            take=dp[ind][tar-arr[ind]];
            dp[ind][tar]=take+nottake;
        }
    }
    return dp[n-1][target];
} 
// Space optimisation
int sumofallpossib(vector<int>& arr,int n,int target)
{
    vector<int> prev(target+1,0),curr(target+1,0);
    for(int tar=0;tar<=target;tar++)
    {
        prev[tar]=(tar%arr[0]==0);
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int tar=0;tar<=target;tar++)
        {
            int nottake=prev[tar];
            int take=0;
            if(arr[ind]<=tar)
            take=curr[tar-arr[ind]];
            curr[ind]=take + nottake;
        }
        prev=curr;
    }
    return prev[target];
}
int main()
{
    int n=3;
    vector<int> arr={1,2,3};
    int target=4;
    cout<<sumofallpossib(arr,n-1,target)<<endl;
    return 0;
}