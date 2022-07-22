// Recursive solution
bool ispalindrome(string str)
{
    int i=0,j=str.length()-1;
    while(i<=j)
    {
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int f(int i,int n,string str)
{
    if(i==n)
        return -1;
    int mini=INT_MAX;
    string temp="";
    for(int j=i;j<n;j++)
    {
        temp+=str[j];
        if(ispalindrome(temp))
        {
            int cost=1+f(j+1,n,str);
            mini=min(mini,cost);
        }
    }
    return mini;
}
int palindromePartitioning(string str) {
    int n=str.size();
    return f(0,n,str);
}
// Memoization solution
#include<bits/stdc++.h>
bool ispalindrome(string str)
{
    int i=0,j=str.length()-1;
    while(i<=j)
    {
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int f(int i,int n,string str,vector<int>& dp)
{
    if(i==n)
        return -1;
    int mini=INT_MAX;
    string temp="";
    if(dp[i]!=-1) return dp[i];
    for(int j=i;j<n;j++)
    {
        temp+=str[j];
        if(ispalindrome(temp))
        {
            int cost=1+f(j+1,n,str,dp);
            mini=min(mini,cost);
        }
    }
    return dp[i]=mini;
}
int palindromePartitioning(string str) {
    int n=str.size();
    vector<int> dp(n,-1);
    return f(0,n,str,dp);
}
// Tabulation solution
#include<bits/stdc++.h>
bool ispalindrome(string str)
{
    int i=0,j=str.length()-1;
    while(i<=j)
    {
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int palindromePartitioning(string str) {
    int n=str.size();
    vector<int> dp(n+1,0);
    dp[n]=-1;
    for(int i=n-1;i>=0;i--)
    {
        int mini=INT_MAX;
        string temp="";
        for(int j=i;j<n;j++)
        {
            temp+=str[j];
            if(ispalindrome(temp))
            {
                int cost=1+dp[j+1];
                mini=min(mini,cost);
            }
        }
        dp[i]=mini;
    }
    return dp[0];
}

