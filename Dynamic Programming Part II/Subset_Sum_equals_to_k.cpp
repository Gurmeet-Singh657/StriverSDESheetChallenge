#include<bits/stdc++.h>
using namespace std;
// Simple recursion
// TC-> exponential
bool f(int arr[],int ind,int target)
{
   if(target==0) return true;
   if(ind==0) return arr[0]==target;
   bool nottake=f(arr,ind-1,target);
   bool take=false;
   if(target>=arr[ind])
   {
       take=f(arr,ind-1,target-arr[ind]);
   }
   return take | nottake;
}
// Memoization
// TC-> O(N*TARGET)
// SC-> O(N*TARGET) + O(N)
bool f(int arr[],int ind,int target,vector<vector<int>>& dp)
{
    if(target==0) return true;
    if(ind==0) return arr[0]==target;
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool nottake=f(arr,ind-1,target,dp);
    bool take=false;
    if(target>=arr[ind])
    take=f(arr,ind-1,target-arr[ind],dp);
    return dp[ind][target]=take|nottake;
}
// Tabulation
// TC-> O(N*TARGET)
// SC-> O(N*TARGET)
bool f(int arr[],int target,int n)
{
    vector<vector<bool>> dp(n,vector<bool>(target,0));
    for(int i=0;i<n;i++)
    dp[i][0]=true;

    if(arr[0]<=target)
    dp[0][arr[0]]=true;

    for(int ind=1;ind<n;ind++)
    {
       for(int k=1;k<=target;k++)
       {
           bool nottake=dp[ind-1][k];
           bool take=true;
           if(k>=arr[ind]) take=dp[ind-1][k-arr[ind]];
           dp[ind][k]=take | nottake;
       } 
    }
    return dp[n-1][target]; // means last tk target bn paya hai
}
// Space optimise
// TC-> O(N*TARGET)
// SC-> O(TARGET)
bool fspaceopt(int arr[],int target,int n)
{
    int k=target;
    vector<bool> prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;
    if(arr[0]<=target)
    prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int tar=1;tar<=k;tar++)
        {
            bool nottake=prev[tar];
            bool take=false;
            if(tar>=arr[ind]) take=prev[tar-arr[ind]];
            curr[tar]=take | nottake;
        }
        prev=curr;
    }
    return prev[target];
}
int main()
{
    int n=4;
    int arr[]={2,3,1,1};
    int target=4;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return 0;
}