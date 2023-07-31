/*
Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int x=0,mx=0;
        unordered_map<int,int>m;
        for(int i=0;i<N;i++)
        {
             x+=A[i];
             
             if(x==K)
                mx=i+1;
           if(m.find(x-K)!=m.end())
            {
                mx=max(mx,i-m[x-K]);
            }
            if(m.find(x)==m.end())
            {
                m[x]=i;
            }
        }
        return mx;
    } 

};