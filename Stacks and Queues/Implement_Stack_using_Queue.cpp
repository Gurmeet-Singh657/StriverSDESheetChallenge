#include<bits/stdc++.h>
using namespace std;
class Stack {
	queue<int> q;
   public:
    Stack() {
       
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
       return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int element) {
        q.push(element);
        for(int i=0;i<q.size()-1;i++)
        {
            int ele=q.front();
            q.pop();
            q.push(ele);
        }
    }

    int pop() {
        if(q.size()==0) return -1;
        int ele=q.front();
        q.pop();
        return ele;
    }

    int top() {
         if(q.size()==0) return -1;
        return q.front();
    }
};