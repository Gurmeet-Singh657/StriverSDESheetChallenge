#include<bits/stdc++.h>
using namespace std;
long double multiply(long double mid,int n)
{
    double pro=1.0;
    for(int i=1;i<=n;i++)
        pro*=mid;
    return pro;
}
long double findNthRootOfM(int n, long long m) {
	// Write your code here.
    long double low=1.0;
    long double  high=(long double)m;
    long double eps=1e-9;
    while((high-low)>eps)
    {
        long double mid=(low+high)/2.0;
        if(multiply(mid,n)>(long double)m)
            high=mid;
        else
            low=mid;
    }
    return low;
}
