/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
*/

#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack()
    {
        queue<int>q1;
        queue<int>q2;
        
    }
    
    void push(int x)
    {
        q1.push(x);
        
    }
    
    int pop()
    {
        if(q1.size()==0)
            return -1;
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        q1.pop();
        while(q2.size()!=0)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
        
    }
    
    int top()
    {
        if(q1.size()==0)
            return -1;
        int x=-1;
        while(q1.size()!=0)
        {
            x=q1.front();
            q2.push(x);
            q1.pop();
        }
        while(q2.size()!=0)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
        
    }
    
    bool empty() {
        if(q1.size()==0)
            return true;
        return false;
    }
};