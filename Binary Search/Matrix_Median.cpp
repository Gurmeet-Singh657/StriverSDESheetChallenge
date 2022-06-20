#include<bits/stdc++.h>
using namespace std;
int countsmallerelts(int find,vector<int>& rows)
{
    int start=0,end=rows.size()-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(rows[mid]<=find)
            start=mid+1;
        else
            end=mid-1;
    }
    return start;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    int start=1,end=1e5;
    while(start<=end)
    {
        int mid=(end-start)/2+start;
        int count=0;
        for(int i=0;i<n;i++)
            count+=countsmallerelts(mid,matrix[i]);
        if(count<=(n*m)/2)
            start=mid+1;
        else
            end=mid-1;
    }
    return start;
}