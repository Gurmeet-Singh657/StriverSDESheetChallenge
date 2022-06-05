#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void Transpose(vector<vector<int>>& mat,int n,int m)
    {
    for(int i=0;i<n;i++)
    {
          for(int j=i+1;j<m;j++)
          {
              swap(mat[i][j],mat[j][i]);
          }
    }
    }
   void Reverserows(vector<vector<int>>& mat,int n,int m)
   {
      for(int i=0;i<n;i++)
      {
         reverse(mat[i].begin(),mat[i].end());
      }
   }
    void rotate(vector<vector<int>>& matrix) {
       Transpose(matrix,matrix.size(),matrix[0].size());
        Reverserows(matrix,matrix.size(),matrix[0].size());
    }
};