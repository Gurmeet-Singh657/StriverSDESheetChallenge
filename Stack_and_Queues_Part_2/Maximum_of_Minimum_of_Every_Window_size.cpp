#include<bits/stdc++.h>
using namespace std;
vector<int> maxMinWindow(vector<int> arr, int n) {
    vector<int> ans(n,INT_MIN);
    stack<int> st;
    for(int i=0;i<=n;i++)
    {
        while(!st.empty() && (i==n || arr[st.top()]>=arr[i]))
        {
            int ele=arr[st.top()];
            st.pop();
            int width;
            if(st.empty())
                width=i;
            else
                width=i-st.top()-1;
            ans[width-1]=max(ele,ans[width-1]);
        }
        st.push(i);
    }
    for(int i=n-2;i>=0;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }
    return ans;
}