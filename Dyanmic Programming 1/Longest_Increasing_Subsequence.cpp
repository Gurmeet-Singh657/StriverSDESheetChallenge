#include<bits/stdc++.h>
using namespace std;
// Simple Recursive
int f(int arr[],int ind,int n,int prev_ind)
{
    if(ind==n)
        return 0;
    
    int maxi=f(arr,ind+1,n,prev_ind);
    if(prev_ind==-1 || arr[ind]>arr[prev_ind])
        maxi=max(maxi,1+f(arr,ind+1,n,ind));
    return maxi;
}
int longestIncreasingSubsequence(int arr[], int n)
{
   return f(arr,0,n,-1);
}

// Memoization
#include<bits/stdc++.h>
int f(int arr[],int ind,int n,int prev_ind,vector<vector<int>>& dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    int maxi=f(arr,ind+1,n,prev_ind,dp);
    if(prev_ind==-1 || arr[ind]>arr[prev_ind])
        maxi=max(maxi,1+f(arr,ind+1,n,ind,dp));
    return dp[ind][prev_ind+1]=maxi;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
   return f(arr,0,n,-1,dp);
}

// Tabulation
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
        {
            int maxi=dp[ind+1][prev_ind+1];
            if(prev_ind==-1 || arr[ind]>arr[prev_ind])
                maxi=max(maxi,1+dp[ind+1][ind+1]);
            dp[ind][prev_ind+1]=maxi;
        }
    }
   return dp[0][0];
}

// Space optimisation
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> next(n+1,0),curr(n+1,0);
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
        {
            int maxi=next[prev_ind+1];
            if(prev_ind==-1 || arr[ind]>arr[prev_ind])
                maxi=max(maxi,1+next[ind+1]);
           curr[prev_ind+1]=maxi;
        }
        next=curr;
    }
   return next[0];
}
// O(n2) solution
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1);
    int maxi=1;
    for(int ind=0;ind<n;ind++)
    {
        for(int prev_ind=0;prev_ind<ind;prev_ind++)
        {
            if(arr[ind]>arr[prev_ind])
                dp[ind]=max(dp[ind],1+dp[prev_ind]);
        }
        maxi=max(maxi,dp[ind]);
    }
    return maxi;
}
// Printing Longest common subsequence
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1),vector<int> hash(n);
    int maxi=1;
    int maxindex=0;
    for(int ind=0;ind<n;ind++)
    {
        hash[ind]=ind;
        for(int prev_ind=0;prev_ind<ind;prev_ind++)
        {
            if(arr[ind]>arr[prev_ind] && 1+dp[prev_ind]>dp[ind])
            {
                 dp[ind]=1+dp[prev_ind];
                 hash[ind]=prev_ind;
            }    
        }
        if(dp[ind]>maxi)
        {
            maxi=dp[ind];
            maxindex=ind;
        }
    }
    vector<int> lis;
    lis.push_back(arr[maxindex]);
    while(hash[maxindex]!=maxindex)
    {
        maxindex=hash[maxindex];
        lis.push_back(arr[maxindex]);
    }
    reverse(lis.begin(),lis.end()); // this is the answer
    return maxi;
    for(auto it:lis)
    cout<<it<<endl;
}

// Very optimised Way using Binary Search
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind]=arr[i];
        }
    }
    return temp.size();
}



