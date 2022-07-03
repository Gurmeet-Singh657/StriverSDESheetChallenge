#include<bits/stdc++.h>
using namespace std;
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int total=0;
    queue<pair<int,int>> q;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j]==2)
            q.push({i,j});
            if(grid[i][j]!=0)
                total++;
        }
    }
    int cnt=0;
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int time=0;
    while(!q.empty())
    {
        int size=q.size();
        cnt+=size;
        for(int i=0;i<size;i++)
        {
            int currrow=q.front().first;
            int currcol=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int letrow=currrow+dx[k];
                int letcol=currcol+dy[k];
                 if(letrow<0 || letcol<0 || letrow>=n || letcol>=m || grid[letrow][letcol]!=1)
                        continue;
                    grid[letrow][letcol]=2;
                    q.push({letrow,letcol});
            }
            
            
        }
        if(!q.empty())time++;
    }
    return total==cnt?time:-1;
}