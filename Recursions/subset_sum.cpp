#include<bits/stdc++.h>
using namespace std;
void findsubsets(int ind,int N,vector<int>& ans,int sum,vector<int>& num)
{
    if(ind==N)
    {
        ans.push_back(sum);
        return;
    }
    findsubsets(ind+1,N,ans,sum+num[ind],num);
    findsubsets(ind+1,N,ans,sum,num);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    findsubsets(0,num.size(),ans,0,num);
    sort(ans.begin(),ans.end());
    return ans;
}