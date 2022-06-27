#include<bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int>& st,int ele)
{
    if(st.empty() || !st.empty() && ele>st.top())
    {
        st.push(ele);
        return;
    }
    int curr=st.top();
    st.pop();
    sortedInsert(st,ele);
    st.push(curr);
}
void sortStack(stack<int> &st)
{
	if(st.empty())
        return;
    int ele=st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st,ele);
}