// Simple Recursive Solution
int f(int i,int j,vector<int>& arr)
{
    if(i==j)
        return 0;
    int mini=1e9;
    for(int k=i;k<=j-1;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr)+f(k+1,j,arr);
        mini=min(mini,steps);
    }
    return mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    return f(1,N-1,arr);
}
// Memoization
int f(int i,int j,vector<int>& arr,vector<vector<int>>& dp)
{
    if(i==j)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=1e9;
    for(int k=i;k<=j-1;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return f(1,N-1,arr,dp);
}
// Tabulation
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,0));
    for(int i=N-1;i>=1;i--)
    {
        for(int j=i+1;j<=N-1;j++)
        {
            int mini=1e9;
            for(int k=i;k<=j-1;k++)
            {
                int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini=min(mini,steps);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][N-1];
}
// since there is no link of elements on either side of left diagonal so we need to maintain i=j as 0
// But it's not right but written for clarity
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,0));
    for(int i=N-1;i>=1;i--)
    {
        for(int j=1;j<=N-1;j++)
        {
            if(i==j)
                continue;
            int mini=1e9;
            for(int k=i;k<=j-1;k++)
            {
                int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini=min(mini,steps);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][N-1];
}