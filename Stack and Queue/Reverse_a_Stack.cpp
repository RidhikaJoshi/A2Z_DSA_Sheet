/*
You are given a stack St. You have to reverse the stack using recursion.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    stack<int>s;

    
    void Reverse(stack<int> &St)
    {
        if(St.size()==0)
         {
             St=s;
             return;
         }
            
        int x=St.top();
        St.pop();
        s.push(x);
        Reverse(St);
        
    }
};