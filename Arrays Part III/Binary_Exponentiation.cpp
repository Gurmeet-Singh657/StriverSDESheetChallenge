#include <bits/stdc++.h> 
using namespace std;
long long findpower(int x,int n,int m)
{
    if(n==1)
        return x;
    long long smul=findpower(x,n/2,m)%m;
    smul=(smul%m * smul%m)%m;
    smul=smul%m;
    if(n%2!=0)
        smul=(smul*x)%m;
    return smul%m;
}
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    return findpower(x,n,m)%m;
}