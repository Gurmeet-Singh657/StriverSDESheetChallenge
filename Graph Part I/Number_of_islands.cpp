#include<bits/stdc++.h>
using namespace std;
void DFS(int **arr,int i,int j,int n,int m)
{
    if(i>=n || i<0 || j>=m || j<0 || arr[i][j]==0)
        return;
    arr[i][j]=0;
    int dx[8]={-1,1,0,0,-1,-1,1,1};
    int dy[8]={0,0,-1,1,1,-1,1,-1};
    for(int k=0;k<8;k++)
    {
        DFS(arr,i+dx[k],j+dy[k],n,m);
    }
}
int getTotalIslands(int** arr, int n, int m)
{
   int count=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(arr[i][j]==1)
           {
               count++;
               DFS(arr,i,j,n,m);
           }
       }
   }
   return count;
}
