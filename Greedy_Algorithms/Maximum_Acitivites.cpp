#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.second>p2.second)
        return false;
//     else if(p1.second==p2.second && p1.first>p2.first )
//         return false;
    return true;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> vec;
    for(int i=0;i<start.size();i++)
        vec.push_back({start[i],finish[i]});
    sort(vec.begin(),vec.end(),cmp);
    int meetings=1;
    int prevmeetingend=vec[0].second;
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i].first>=prevmeetingend)
        {
            meetings++;
            prevmeetingend=vec[i].second;
        }
            
    }
    return meetings;
}