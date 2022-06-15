#include<bits/stdc++.h>
using namespace std;
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int platforms=1;
    int maxi=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            platforms++;
            i++;
        }
        else
        {
            platforms--;
            j++;
        }
        maxi=max(maxi,platforms);
            
    }
    return maxi;
}