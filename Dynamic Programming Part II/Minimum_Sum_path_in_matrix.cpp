// Recursion
// TC-> exponential
int f(int i,int j,vector<vector<int>>& grid)
{
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return 1e9;
    int up=grid[i][j]+f(i-1,j,grid);
    int left=grid[i][j]+f(i,j-1,grid);
    return min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    return f(grid.size()-1,grid[0].size()-1,grid);
    
}
// Memoization
// TC-> O(N*M)
// SC-> O(N*M) + O(N*M)
int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
{
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=grid[i][j]+f(i-1,j,grid,dp);
    int left=grid[i][j]+f(i,j-1,grid,dp);
    return dp[i][j]=min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    return f(grid.size()-1,grid[0].size()-1,grid,dp);
    
}
// Tabulation
// TC-> O(N*M)
// SC-> O(N*M)
int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(i==0 && j==0) dp[i][j]=grid[i][j];
            else
            {
                int up=grid[i][j]+(i>0?dp[i-1][j]:1e9);
                int left=grid[i][j]+(j>0?dp[i][j-1]:1e9);
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[grid.size()-1][grid[0].size()-1];
    
}
// Space optimisation
// TC-> O(N*M)
// SC-> O(M)
int minSumPath(vector<vector<int>> &grid) {
    vector<int> prev(grid[0].size(),-1);
    for(int i=0;i<grid.size();i++)
    {
        vector<int> curr(grid[0].size());
        for(int j=0;j<grid[0].size();j++)
        {
            if(i==0 && j==0) curr[j]=grid[i][j];
            else
            {
                int up=grid[i][j]+(i>0?prev[j]:1e9);
                int left=grid[i][j]+(j>0?curr[j-1]:1e9);
                curr[j]=min(up,left);
            }
        }
        prev=curr;
    }
    return prev[grid[0].size()-1];
    
}