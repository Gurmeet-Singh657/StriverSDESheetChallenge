// Recursive solution
int f(int ind,vector<int>& rack,int n,int prev)
{
    if(ind==n)
        return 0;
    int nottake=f(ind+1,rack,n,prev);
    int take=INT_MIN;
    if(rack[ind]>prev)
        take=rack[ind]+f(ind+1,rack,n,rack[ind]);
    return max(take,nottake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	return f(0,rack,n,0);
}
// Memoization solution
int f(int ind,vector<int>& rack,int n,int prev,vector<vector<int>>& dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    int nottake=f(ind+1,rack,n,prev,dp);
    int take=INT_MIN;
    if(rack[ind]>prev)
        take=rack[ind]+f(ind+1,rack,n,rack[ind],dp);
    return dp[ind][prev]=max(take,nottake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    int maxi=-1;
    for(int i=0;i<n;i++)
        maxi=max(maxi,rack[i]);
    vector<vector<int>> dp(n,vector<int>(maxi+1,-1));
	return f(0,rack,n,0,dp);
}
// Tabulation solution
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    int maxi=-1;
    for(int i=0;i<n;i++)
        maxi=max(maxi,rack[i]);
    vector<vector<int>> dp(n+1,vector<int>(maxi+1,0));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev=0;prev<=maxi;prev++)
        {
            int nottake=dp[ind+1][prev];
            int take=INT_MIN;
            if(rack[ind]>prev)
                take=rack[ind]+dp[ind+1][rack[ind]];
            dp[ind][prev]=max(take,nottake);
        }
    }
	return dp[0][0];
}
// Space optimisation solution
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    int maxi=-1;
    for(int i=0;i<n;i++)
        maxi=max(maxi,rack[i]);
    vector<int> ahead(maxi+1,0),curr(maxi+1,0);
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev=0;prev<=maxi;prev++)
        {
            int nottake=ahead[prev];
            int take=INT_MIN;
            if(rack[ind]>prev)
                take=rack[ind]+ahead[rack[ind]];
            curr[prev]=max(take,nottake);
        }
       ahead=curr;
    }
	return ahead[0];
}