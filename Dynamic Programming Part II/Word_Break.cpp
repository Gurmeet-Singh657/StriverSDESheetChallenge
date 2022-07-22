// Recursive solution
#include<bits/stdc++.h>
bool f(string& target,int ind,int n,unordered_set<string>& st)
{
    if(ind==n)
        return true;
   for(int i=ind;i<n;i++)
   {
       string currstring=target.substr(ind,i-ind+1);
       if(st.find(currstring)!=st.end())
       {
           if(f(target,i+1,n,st))
           return true;
       }
   }
    return false;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_set<string> st;
    for(int i=0;i<n;i++)
        st.insert(arr[i]);
    return f(target,0,target.size(),st);
}
// Memoization solution
#include<bits/stdc++.h>
bool f(string& target,int ind,int n,unordered_set<string>& st,vector<int>& dp)
{
    if(ind==n)
        return true;
    if(dp[ind]!=-1) return dp[ind];
   for(int i=ind;i<n;i++)
   {
       string currstring=target.substr(ind,i-ind+1);
       if(st.find(currstring)!=st.end())
       {
           if(f(target,i+1,n,st,dp))
           return dp[ind]=true;
       }
   }
    return dp[ind]=false;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_set<string> st;
    int tsize=target.size();
    vector<int> dp(tsize,-1);
    for(int i=0;i<n;i++)
        st.insert(arr[i]);
    return f(target,0,tsize,st,dp);
}
// Tabulated solution
#include<bits/stdc++.h>
bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_set<string> st;
    int tsize=target.size();
    vector<int> dp(tsize+1,0);
    dp[tsize]=1;
    for(int i=0;i<n;i++)
        st.insert(arr[i]);
    for(int ind=tsize-1;ind>=0;ind--)
    {
        for(int i=ind;i<tsize;i++)
        {
            string currstring=target.substr(ind,i-ind+1);
            if(st.find(currstring)!=st.end())
            {
                if(dp[i+1]==1)
                {
                    dp[ind]=1;
                    break;
                }
                    
            }
        }
    }
    return dp[0];
}