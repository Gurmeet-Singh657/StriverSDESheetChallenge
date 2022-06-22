#include<bits/stdc++.h>
using namespace std;
bool ispossible(long long mid,vector<int> time,int n)
{
    int daycount=1;
    int i=0;
    long long timecount=0;
    while(i<time.size())
    {
        if(time[i]+timecount<=mid)
        {
            timecount+=time[i];
        }
        else
        {
             daycount++;
            timecount=time[i];
        }
        if(daycount>n || time[i]>mid)
            return false;
        i++;
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long sum=0;
    int mini=INT_MAX;
    for(int i=0;i<time.size();i++)
    {
        sum+=time[i];
        mini=min(mini,time[i]);
    }
    long long low=mini,high=sum;
    long long answer=0;
    while(low<=high)
    {
        long long mid=(low+high)/2;
        if(ispossible(mid,time,n))
        {
            answer=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return answer;
}