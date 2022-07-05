#include<bits/stdc++.h>
using namespace std;
vector<int> makezarray(string s)
{
    vector<int> z(s.length(),0);
    int n=s.length();
    int l=0,r=0;
    for(int i=1;i<n;i++)
    {
        if(i>r)
        {
            l=r=i;
            while(r<n && s[r]==s[r-l])
                r++;
            z[i]=(r-l);
            r--;
        }
        else
        {
            int index=i-l;
            if(i+z[index]<=r)
            {
                z[i]=z[index];
            }
            // But if boundary crossed so this means 
            // I am not sure given + more elements are possible
            else
            {
                l=i;
                while(r<n && s[r]==s[r-l])
                    r++;
                z[i]=(r-l);
                r--;
            }
        }
    }
    return z;
}
int zAlgorithm(string s, string p, int n, int m)
{
    string final=p+'$'+s;
    vector<int> Zarray=makezarray(final);
	int count=0;
    for(int i=0;i<Zarray.size();i++)
    {
        if(Zarray[i]==p.length())
            count++;
    }
    return count;
}