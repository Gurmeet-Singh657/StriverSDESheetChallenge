#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int i=n-2;
    while(i>=0 && permutation[i]>=permutation[i+1])
    {
        i--;
    }
    int j=n-1;
    if(i>=0)
    {
        while(j>i && permutation[j]<permutation[i])
        {
           j--;
        }
        swap(permutation[i],permutation[j]);
        reverse(permutation.begin()+i+1,permutation.end());
    }
    else
        reverse(permutation.begin(),permutation.end());
    
    return permutation;
    
}