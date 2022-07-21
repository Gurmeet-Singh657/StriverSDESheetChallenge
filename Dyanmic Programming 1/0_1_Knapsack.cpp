#include<bits/stdc++.h>
using namespace std;
int findbestpossiblevalue(int wt[],int val[],int ind,int weight)
{
    if(ind==0)
    {
        if(wt[ind]<=weight) return val[ind];
        else return 0;
    }
    int nottake=findbestpossiblevalue(wt,val,ind-1,weight);
    int take=INT_MIN;
    if(wt[ind]<=weight)
    int take=val[ind]+findbestpossiblevalue(wt,val,ind-1,weight-wt[ind]);
    return max(take,nottake);
}
// Memoization
// Time complexity - O(N*W)
// Space complexity - O(N*W) + O(N)
// vector<vector<int>> dp(ind,vector<int>(weight+1,-1))
int f(int wt[],int val[],int ind,int weight,vector<vector<int>>& dp)
{
    if(ind==0)
    {
        if(wt[ind]<=weight) return val[ind];
        else
        return 0;
    }
    if(dp[ind][weight]!=-1) return dp[ind][weight];
    int nottake=f(wt,val,ind-1,weight,dp);
    int take=INT_MIN;
    if(wt[ind]<=weight)
    int take=val[ind]+f(wt,val,ind-1,weight-wt[ind],dp);
    return dp[ind][weight]=max(take,nottake);
}
// Tabulation
int f(int wt[],int val[],int n,int weight)
{
    vector<vector<int>> dp(n,vector<int>(weight+1,0));
    for(int i=wt[0];i<=weight;i++)
    {
        dp[0][i]=val[0];
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int w=0;w<=weight;w++)
        {
            int nottake=dp[ind-1][w];
            int take=INT_MIN;
            if(wt[ind]<=w)
            {
                take=val[ind]+dp[ind-1][w-wt[ind]];
            }
            dp[ind][w]=max(nottake,take);
        }
    }
    return dp[n-1][weight];
}
// Space optimised
int f(int wt[],int val[],int n,int weight)
{
    vector<int> prev(weight+1,0),curr(weight+1,0);
    for(int i=wt[0];i<=weight;i++)
    {
        prev[i]=val[0];
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int w=0;w<=weight;w++)
        {
            int nottake=prev[w];
            int take=INT_MIN;
            if(wt[ind]<=w)
            take=val[ind]+prev[w-wt[ind]];
            curr[ind]=max(take,nottake);
        }
        prev=curr;
    }
    return prev[weight];
}
// More space optimised
int f(int wt[],int val[],int n,int weight)
{
    vector<int> prev(weight+1,0);
    for(int i=wt[0];i<=weight;i++)
    {
        prev[i]=val[0];
    }
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int w=0;w<=weight;w++)
        {
            int nottake=prev[w];
            int take=INT_MIN;
            if(wt[ind]<=w)
            take=val[ind]+prev[w-wt[ind]];
            prev[ind]=max(take,nottake);
        }
    }
    return prev[weight];
}
int main()
{
    int n=3;
    int wt[3]={3,4,5};
    int value[3]={30,40,60};
    int bagwt=8;
    cout<<findbestpossiblevalue(wt,value,n-1,bagwt);
    return 0;
}