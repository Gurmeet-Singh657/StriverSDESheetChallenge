#include<bits/stdc++.h>
using namespace std;
void Mazepaths(int i,int j,vector<vector<int>>& maze,vector<int>& visited,vector<vector<int>>& answer,int n)
{
    if(i==n-1 && j==n-1)
    {
        visited[i*n+j]=true;
        answer.push_back(visited);
        visited[i*n+j]=false;
        return;
    }
    if(i>=n || j>=n || i<0 || j<0 || maze[i][j]==0 || visited[i*n+j]==1)
        return;
    
    visited[i*n+j]=true;
    Mazepaths(i+1,j,maze,visited,answer,n);
    Mazepaths(i,j+1,maze,visited,answer,n);
    Mazepaths(i,j-1,maze,visited,answer,n);
    Mazepaths(i-1,j,maze,visited,answer,n);
    visited[i*n+j]=false;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<int> visited(n*n,0);
    vector<vector<int>> answer;
    Mazepaths(0,0,maze,visited,answer,n);
    return answer;
}