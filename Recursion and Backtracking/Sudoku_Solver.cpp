#include<bits/stdc++.h>
using namespace std;
bool isSafe(int matrix[9][9],int i,int j,int val)
{
    // For row
    for(int k=0;k<9;k++)
    {
        if(matrix[i][k]==val)
            return false;
    }
    // for col
    for(int k=0;k<9;k++)
    {
        if(matrix[k][j]==val)
            return false;
    }
    // for Diagonal
    int currrow=3*(i/3);
    int currcol=3*(j/3);
    i=0,j=0;
    while(i<3)
    {
        j=0;
        while(j<3)
        {
            if(matrix[currrow+i][currcol+j]==val)
                return false;
            j++;
        }
        i++;
    }
    return true;
}
bool Sudokuchecker(int matrix[9][9],int i,int j)
{
    if(i==9)
    {
        return true;
    }
    if(j==9)
    {
        return Sudokuchecker(matrix,i+1,0);
    }
    if(matrix[i][j]!=0)
        return Sudokuchecker(matrix,i,j+1);
    for(int pos=1;pos<=9;pos++)
    {
        if(isSafe(matrix,i,j,pos))
        {
            matrix[i][j]=pos;
            if(Sudokuchecker(matrix,i,j+1))
                return true;
            matrix[i][j]=0;
        }
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return Sudokuchecker(matrix,0,0);
}
