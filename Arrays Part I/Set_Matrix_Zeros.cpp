#include <bits/stdc++.h> 
using namespace std;
void Setrowsandcoltozero(vector<vector<int>>& matrix,set<int> rown,set<int> coln)
{
    for(auto row:rown)
    for(int i=0;i<matrix[0].size();i++)
        matrix[row][i]=0;
    
    for(auto col:coln)
    for(int i=0;i<matrix.size();i++)
        matrix[i][col]=0;
}
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    set<int> rows;
    set<int> cols;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    Setrowsandcoltozero(matrix,rows,cols);
}