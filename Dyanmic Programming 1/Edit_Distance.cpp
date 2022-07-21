#include<bits/stdc++.h>
using namespace std;
// Recursive approach
// TC-> exponential
int f(int i,int j,string str1,string str2)
{
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    if(str1[i]==str2[j])
        return 0+f(i-1,j-1,str1,str2);
    return min(1+f(i-1,j,str1,str2),min(1+f(i-1,j-1,str1,str2),1+f(i,j-1,str1,str2)));
}
int editDistance(string str1, string str2)
{
    return f(str1.length()-1,str2.length()-1,str1,str2);
}

// Memoization
// TC-> O(N*M)
// SC-> O(N*M) + O(N*M)
int f(int i,int j,string &str1,string &str2,vector<vector<int>>& dp)
{
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i]==str2[j])
        return dp[i][j]=0+f(i-1,j-1,str1,str2,dp);
    return dp[i][j]=min(1+f(i-1,j,str1,str2,dp),min(1+f(i-1,j-1,str1,str2,dp),1+f(i,j-1,str1,str2,dp)));
}
int editDistance(string str1, string str2)
{
    int n=str1.length();
    int m=str2.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(str1.length()-1,str2.length()-1,str1,str2,dp);
}

// Memoization shifted by one index
// TC-> O(N*M)
// SC-> O(N*M) + O(N*M)
int f(int i,int j,string &str1,string &str2,vector<vector<int>>& dp)
{
    if(i==0)
        return j;
    if(j==0)
        return i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i-1]==str2[j-1])
        return dp[i][j]=0+f(i-1,j-1,str1,str2,dp);
    return dp[i][j]=min(1+f(i-1,j,str1,str2,dp),min(1+f(i-1,j-1,str1,str2,dp),1+f(i,j-1,str1,str2,dp)));
}
int editDistance(string str1, string str2)
{
    int n=str1.length();
    int m=str2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return f(n,m,str1,str2,dp);
}

// Tabulation
// TC-> O(N*M)
// SC-> O(N*M)
int editDistance(string str1, string str2)
{
    int n=str1.length();
    int m=str2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++)
    {
        dp[0][j]=j;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=0+dp[i-1][j-1];
            else 
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }
    return dp[n][m];
}

// Space optimised
// TC-> O(N*M)
// SC-> O(M)
int editDistance(string str1, string str2)
{
    int n=str1.length();
    int m=str2.length();
    vector<int> prev(m+1,0),curr(m+1,0);
    prev[0]=0;
    for(int j=0;j<=m;j++)
    {
        prev[j]=j;
    }
    for(int i=1;i<=n;i++)
    {
        curr[0]=i;
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
                curr[j]=0+prev[j-1];
            else 
                curr[j]=1+min(prev[j],min(prev[j-1],curr[j-1]));
        }
        prev=curr;
    }
    return prev[m];
}