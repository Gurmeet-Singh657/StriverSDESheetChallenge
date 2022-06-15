#include<bits/stdc++.h>
using namespace std;
struct meeting
{
    int start;
    int end;
    int pos;
};
// NOTE - starting points will never be same
bool comparator(meeting m1,meeting m2)
{
    if(m1.end<m2.end) return true;
    else if(m1.end==m2.end && m1.pos<m2.pos) return true; // if ending points are same of the meeting so lower index preferred
    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    meeting m[start.size()];
    for(int i=0;i<start.size();i++)
        m[i]={start[i],end[i],i+1};
    sort(m,m+start.size(),comparator);
    vector<int> answer;
    int limit=m[0].end;
    answer.push_back(m[0].pos);
    for(int i=1;i<start.size();i++)
    {
        if(m[i].start>limit)
        {
            answer.push_back(m[i].pos);
            limit=m[i].end;
        }
    }
    return answer;
}