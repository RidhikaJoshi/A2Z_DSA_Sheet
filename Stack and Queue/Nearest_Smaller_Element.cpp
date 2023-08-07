/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::prevSmaller(vector<int> &A)
{
    stack<int>st;
    vector<int>res;
    for(int i=0;i<A.size();i++)
    {
        if(st.size()==0)
            res.push_back(-1);
        else if(st.size()!=0 && st.top()<A[i])
            res.push_back(st.top());
        else
        {
            while(st.size()!=0 && st.top()>=A[i])
                st.pop();
            if(st.size()==0)
                res.push_back(-1);
            else    
                res.push_back(st.top());
        }
        st.push(A[i]);
    }
    return res;
}