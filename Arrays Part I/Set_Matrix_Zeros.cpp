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

// Optimised Approach 
void setZeros(vector<vector<int>> &matrix)
{
    bool row=false,col=false; // marked for 0,0 element
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==0)
            {
                if(j==0)
                    col=true;
                if(i==0)
                    row=true;
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }
    for(int i=1;i<matrix.size();i++)
    {
        for(int j=1;j<matrix[0].size();j++)
        {
            if(matrix[i][0]==0 || matrix[0][j]==0)
                matrix[i][j]=0;
        }
    }
    if(row)
        for(int i=0;i<matrix[0].size();i++)
            matrix[0][i]=0;
    if(col)
        for(int i=0;i<matrix.size();i++)
            matrix[i][0]=0;
            
   
}