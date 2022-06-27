#include<bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string expression)
{
    stack<int> st;
    for(int i=0;i<expression.size();i++)
    {
        if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{')
            st.push(expression[i]);
        else
        {
            if(st.empty()) // if there is no one to pair it
                return false;
            else
            {
                if(st.top()=='(' && expression[i]==')' || st.top()=='[' && expression[i]==']' || st.top()=='{' && expression[i]=='}')
                    st.pop();
                else
                    return false;
            }
        }
    }
    if(!st.empty())
        return false;
    return true;
}