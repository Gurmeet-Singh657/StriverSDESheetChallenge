#include<bits/stdc++.h> 
using namespace std;
int largestRectangle(vector < int > & heights) {
   int rightsmaller[heights.size()];
   int leftsmaller[heights.size()];
     stack<int> st;
     for(int i=0;i<heights.size();i++)
     {
         while(!st.empty() && heights[i]<=heights[st.top()])
         {
             st.pop();
         }
         if(!st.empty())
             leftsmaller[i]=st.top();
         else
             leftsmaller[i]=-1;
         st.push(i);
     }
     stack<int> st2;
     for(int i=heights.size()-1;i>=0;i--)
     {
         while(!st2.empty() && heights[i]<=heights[st2.top()])
         {
             st2.pop();
         }
         if(!st2.empty())
             rightsmaller[i]=st2.top();
         else
             rightsmaller[i]=heights.size();
         st2.push(i);
     }
     int maxarea=INT_MIN;
     for(int i=0;i<heights.size();i++)
     {
         int width=rightsmaller[i]-leftsmaller[i]-1;
         maxarea=max(maxarea,width*heights[i]);
     }
     return maxarea;
 }

 // optimised Way
 #include<bits/stdc++.h> 
int largestRectangle(vector < int > & heights) {
    int n=heights.size();
    stack<int> st;
    int maxarea=INT_MIN;
    for(int i=0;i<=n;i++)
    {
        while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
        {
           int index=st.top();
            st.pop();
            int width;
            if(!st.empty())
                width=i-st.top()-1;
           else
               width=i;
           int currarea=width*heights[index];
            maxarea=max(currarea,maxarea);
        }
        st.push(i);
    }
    return maxarea;
 }