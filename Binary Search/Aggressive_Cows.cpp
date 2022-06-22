#include<bits/stdc++.h>
using namespace std;
bool ispossible(int mid,int c,vector<int>& positions,int n)
{
    int cow=1;
    int prevposition=positions[0];
    int i=1;
    while(i<n)
    {
        if(positions[i]-prevposition>=mid)
        {
            cow++;
            prevposition=positions[i];
        }
        if(cow==c)
            return true;
        i++;
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
    int low=1,high=positions[n-1]-positions[0];
    int res=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ispossible(mid,c,positions,n))
        {
            res=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return res;
}