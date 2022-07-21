#include<bits/stdc++.h>
using namespace std;
// Linear Search solution -> TLE
int cutLogs(int n, int k) // n-> no. of floors k-> number of eggs
{
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++) // denotes the egg
    { 
        for(int j=1;j<=k;j++) // denotes the floor
        {
            if(i==1) dp[i][j]=j;
            else if(j==1) dp[i][j]=1;
            else 
            {
                int mini=INT_MAX;
                for(int mj=j-1,pj=0;mj>=0;mj--,pj++)
                {
                    int v1=dp[i][mj]; // egg survives
                    int v2=dp[i-1][pj]; // egg breaks
                    int maxi=max(v1,v2);
                    mini=min(mini,maxi);
                }
                dp[i][j]=mini+1;
            }
        }
    }
    return dp[n][k];
}
// Binary Search solution
#include<bits/stdc++.h>
int cutLogs(int n, int k) // n-> no. of floors k-> number of eggs
{
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++) // denotes the egg
    { 
        for(int j=1;j<=k;j++) // denotes the floor
        {
            if(i==1) dp[i][j]=j;
            else if(j==1) dp[i][j]=1;
            else 
            {
                int mini=INT_MAX;
                int start=1,end=j;
                while(start<=end)
                {
                    int mid=(start+end)/2;
                    int v1=dp[i-1][mid-1]; // egg breaks
                    int v2=dp[i][j-mid]; // egg survives
                    int maxi=max(v1,v2);
                    if(v1<v2)
                        start=mid+1;
                    else 
                        end=mid-1;
                    mini=min(mini,maxi);
                }
                dp[i][j]=mini+1;
            }
        }
    }
    return dp[n][k];
}


