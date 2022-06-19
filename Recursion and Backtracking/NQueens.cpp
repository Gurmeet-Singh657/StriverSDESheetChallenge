bool isSafe(int i,int j,vector<vector<int>>& chessboard)
{
    for(int row=0;row<chessboard.size();row++)
    {
        if(chessboard[row][j]==1)
            return false;
    }
    for(int col=0;col<chessboard.size();col++)
    {
        if(chessboard[i][col]==1)
            return false;
    }
    int currrow=i,currcol=j;
    while(currrow>=0 && currcol>=0)
    {
        if(chessboard[currrow][currcol]==1)
            return false;
        currrow--;
        currcol--;
    }
    currrow=i,currcol=j;
    while(currrow>=0 && currcol<chessboard.size())
    {
        if(chessboard[currrow][currcol]==1)
            return false;
        currrow--;
        currcol++;
    }
    return true;
}
void NQueen(vector<vector<int>>& chessboard,int ind,vector<vector<int>>& ans)
{
    if(ind==chessboard.size())
    {
        vector<int> finalans;
        for(int i=0;i<chessboard.size();i++)
        {
            for(int j=0;j<chessboard.size();j++)
            {
                finalans.push_back(chessboard[i][j]);
            }
        }
        ans.push_back(finalans);
        return;
    }
    for(int j=0;j<chessboard.size();j++)
    {
        if(isSafe(ind,j,chessboard))
        {
            chessboard[ind][j]=1;
            NQueen(chessboard,ind+1,ans);
            chessboard[ind][j]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> chessboard(n,vector<int>(n,0));
    vector<vector<int>> ans;
    NQueen(chessboard,0,ans);
    return ans;
}