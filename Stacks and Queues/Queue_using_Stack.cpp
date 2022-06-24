#include<bits/stdc++.h>
using namespace std;
class Queue {
    stack<int> input;
    stack<int> output;
    
    public:
    Queue() {
       
    }

    void enQueue(int val) {
        input.push(val);
    }

    int deQueue() {
        if(isEmpty())
            return -1;
       if(output.empty())
       {
           while(!input.empty())
           {
              output.push(input.top());
               input.pop();
           }
       }
        int ele=output.top();
        output.pop();
        return ele;
    }

    int peek() {
        if(isEmpty()) return -1;
        if(output.empty())
       {
           while(!input.empty())
           {
               output.push(input.top());
               input.pop();
           }
       }
       return output.top();
    }

    bool isEmpty() {
        return input.empty() && output.empty();
    }
};