#include <bits/stdc++.h>
using namespace std;
// Normal Recursion
// TC - exponential
// SC - O(rodlength)// stack space
int f(int ind, int rodlength, vector<int> &price)
{
    if (ind == 0)
    {
        return rodlength * price[0]; // no edge case since last index represent rod length 1 so it will always be true
    }
    int nottake = f(ind - 1, rodlength, price);
    int take = INT_MIN;
    if (ind + 1 <= rodlength) // ind+1 since rodlength is based on 1 based indexing
        take = price[ind] + f(ind, rodlength - ind - 1, price);
    return max(take, nottake);
}
// Memoization
// tc- O(N*rodlength)
// sc - O(N* rodlength) + O(N)
int f(int ind, int rodlength, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return rodlength * price[0];
    if (dp[ind][rodlength] != -1)
        return dp[ind][rodlength];
    int nottake = f(ind - 1, rodlength, price);
    int take = INT_MIN;
    if (ind + 1 <= rodlength)
        take = price[ind] + f(ind, rodlength - ind - 1, price, dp);
    return dp[ind][rodlength] = max(nottake, take);
}
// tabulation
// tc - O(N*rodlength)
// sc - O(N*rodlength)
int f(int n, int rodlength, vector<int> &price)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    // Base case
    for (int i = 0; i <= rodlength; i++)
        dp[0][i] = rodlength * price[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int len = 0; len <= rodlength; len++)
        {
            int nottake = dp[ind - 1][len];
            int take = INT_MIN;
            if (ind + 1 <= len)
                take = price[ind] + dp[ind][len - ind - 1];
            dp[ind][len] = max(take, nottake);
        }
    }
    return dp[n - 1][rodlength];
}
// Space optimisation
int f(int n,vector<int>& price)
{
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int i=0;i<=n;i++)
    prev[i]=n*price[0];
    for(int ind=1;ind<n;ind++)
    {
        for(int len=0;len<=n;len++)
        {
            int nottake=prev[len];
            int take=INT_MIN;
            if(ind+1<=len)
            take=curr[len-ind-1];
            curr[ind]=max(take,nottake);
        }
        prev=curr;
    }
    return prev[n];
}
// More space optimisation
int f(int n,vector<int>& price)
{
    vector<int> prev(n+1,0);
    for(int i=0;i<=n;i++)
    prev[i]=n*price[0];
    for(int ind=1;ind<n;ind++)
    {
        for(int len=0;len<=n;len++)
        {
            int nottake=prev[len];
            int take=INT_MIN;
            if(ind+1<=len)
            take=prev[len-ind-1];
            prev[ind]=max(take,nottake);
        }
    }
    return prev[n];
}
int main()
{
    int rodlength = 5;
    vector<int> price = {2, 5, 7, 8, 10};
    cout << f(5, rodlength, price) << endl;
    return 0;
}