#include<bits/stdc++.h>
using namespace std;
// Implement class for minStack.
class minStack
{
	int mini;
    stack<int> st;
	public:
		minStack() 
		{ 
            mini=INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
            if(st.empty())
            {
                mini=num;
                st.push(num);
                return;
            }
            // else if stack is not empty
            if(num<mini)
            {
                st.push(2*num-mini);
                mini=num;
            }
            else
                st.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(st.empty()) return -1;
            int num=st.top();
            if(num<mini)
            {
                int currmin=mini;
                mini=2*mini-num;
                st.pop();
                return currmin;
            }
            st.pop();
            return num;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
            if(st.empty()) return -1;
			if(st.top()<mini)
            {
                return mini;
            }
            return st.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
            if(st.empty()) return -1;
			return mini;
		}
};