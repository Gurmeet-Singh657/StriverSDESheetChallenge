/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

#include<bits/stdc++.h>
using namespace std;
// TLE solution

int findCelebrity(int n) {
 	for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            // if i knows j
            if(i!=j && knows(i,j))
                break;
        }
        // checking if all people knows the i
        if(j==n)
        {
            int k;
            for(k=0;k<n;k++)
            {
                if(i!=k && !knows(k,i))
                    break;
            }
            if(k==n)
            {
                return i;
            }
        }     
    }
    return -1;
}

// optimised soln
int findCelebrity(int n) {
 	stack<int> st;
    for(int i=0;i<n;i++)
        st.push(i);
    while(st.size()>1)
    {
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(knows(a,b))
            st.push(b);
        else
            st.push(a);
    }
    int curr=st.top();
    st.pop();
    // Verification
    for(int i=0;i<n;i++)
    {
        if(i!=curr && (!knows(i,curr) || knows(curr,i)))
            return -1;
    }
    return curr;
}
