#include <bits/stdc++.h>
using namespace std; 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> ans;
    for(int i=0;i<n;i++)
    {
        long long int mul=1;
        vector<long long int> currans;
        for(int j=0;j<=i;j++)
        {
            currans.push_back(mul);
            mul=mul*(i-j)/(j+1);
        }
        ans.push_back(currans);
    }
    return ans;
}
