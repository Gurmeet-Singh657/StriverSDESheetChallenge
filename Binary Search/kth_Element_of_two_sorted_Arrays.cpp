#include<bits/stdc++.h>
using namespace std;
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
   if(m>n)
       return ninjaAndLadoos(row2,row1,n,m,k);
    
    int low=(k>n?k-n:0),high=(k>=m?m:k);
    while(low<=high)
    {
        int cut1=low+(high-low)/2;
        int cut2=k-cut1;
        int l1=cut1>0?row1[cut1-1]:INT_MIN;
        int l2=cut2>0?row2[cut2-1]:INT_MIN;
        int r1=cut1<m?row1[cut1]:INT_MAX;
        int r2=cut2<n?row2[cut2]:INT_MAX;
        if(l1<=r2 && l2<=r1)
            return max(l1,l2);
        else if(l1>r2)
            high=cut1-1;
        else if(l2>r1)
            low=cut1+1;
    }
    return 1;
}