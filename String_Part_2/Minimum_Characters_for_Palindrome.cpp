#include<bits/stdc++.h>
using namespace std;
vector<int> generatekmp(string str)
{
    int n=str.length();
    vector<int> kmp(n,0);
    int j=0;
    int i=1;
    while(i<n)
    {
        if(str[i]==str[j])
        {
            kmp[i]=j+1;
            j++;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=kmp[j-1];
            }
            else
            {
                kmp[i]=0;
                i++;
            }
        }
    }
    return kmp;
}
int minCharsforPalindrome(string str) {
	string final=str+'$';
    reverse(str.begin(),str.end());
    final+=str;
    vector<int> kmp=generatekmp(final);
    return str.length()-kmp.back();
}
