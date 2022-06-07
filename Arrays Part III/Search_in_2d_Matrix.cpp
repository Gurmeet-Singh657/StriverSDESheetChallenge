#include <bits/stdc++.h> 
#include <vector>
using namespace std;

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    int i=0,j=mat[0].size()-1;
    while(i<m && j>=0)
    {
        if(mat[i][j]==target)
            return true;
        else if(mat[i][j]>target)
            j--;
        else
            i++;
    }
    return false;
}
// Leetcode solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int start=0,end=(matrix.size()*matrix[0].size()) -1;
        int col=matrix[0].size();
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            int rowno=mid/col;
            int colno=mid%col;
            int val=matrix[rowno][colno];
            if(val==target)
                return true;
            else if(val>target)
                end=mid-1;
            else
                start=mid+1;
            
        }
        return false;
    }
};