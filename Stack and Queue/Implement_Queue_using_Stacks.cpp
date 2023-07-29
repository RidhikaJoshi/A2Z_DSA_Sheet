
/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/

#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
   stack<int>st1;
    stack<int>st2;
    MyQueue() 
    {
        stack<int>st1;
        stack<int>st2;
    }
    
    void push(int x)
    {
        st1.push(x);
        
    }
    
    int pop()
    {
        while(st1.size()!=0)
        {
            st2.push(st1.top());
            st1.pop();
        }
        int x=-1;
        if(st2.size()!=0)
        {
             x=st2.top();
            st2.pop();
        }
        while(st2.size()!=0)
        {
            st1.push(st2.top());
            st2.pop();
        }
        return x;
        
    }
    
    int peek()
    {
        while(st1.size()!=0)
        {
            st2.push(st1.top());
            st1.pop();
        }
        int x=-1;
        if(st2.size()!=0)
        {
             x=st2.top();
        }
        while(st2.size()!=0)
        {
            st1.push(st2.top());
            st2.pop();
        }
        return x;
        
    }
    
    bool empty()
    {
        if(st1.size()==0)
            return true;

        return false;
        
    }
};