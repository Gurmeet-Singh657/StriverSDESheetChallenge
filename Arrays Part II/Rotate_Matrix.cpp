#include <bits/stdc++.h> 
using namespace std;
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int startrow=0,endrow=mat.size()-1,startcol=0,endcol=mat[0].size()-1;
    if(n==1 || m==1) return;
    while(startrow<endrow && startcol<endcol)
    {
        int temp=mat[startrow][startrow];
        for(int i=startcol+1;i<=endcol;i++)
        {
            swap(temp,mat[startrow][i]);
        }
        startrow++;
        for(int i=startrow;i<=endrow;i++)
        {
            swap(temp,mat[i][endcol]);
        }
        endcol--;
        for(int i=endcol;i>=startcol;i--)
        {
            swap(temp,mat[endrow][i]);
        }
        endrow--;
         for(int i=endrow;i>=startrow-1;i--)
        {
            swap(temp,mat[i][startcol]);
        }
        startcol++;
    }
    

}