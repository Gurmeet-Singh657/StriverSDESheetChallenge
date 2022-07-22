#include<bits/stdc++.h>
bool comparator(vector<int> j1,vector<int> j2)
{
    return j1[1]>j2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    bool check[3001]={0};
    sort(jobs.begin(),jobs.end(),comparator);
    int profit=0;
    for(int i=0;i<jobs.size();i++)
    {
        int currdeadline=jobs[i][0];
        while(currdeadline>0 && check[currdeadline]==1)
            currdeadline--;
        if(currdeadline>=1)
        {
            profit+=jobs[i][1];
            check[currdeadline]=1;
        }
    }
    return profit;
}
