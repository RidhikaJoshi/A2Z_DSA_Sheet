/*
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int missingNumber(vector<int>& array, int n)
    {
        unordered_set<int>st;
        for(int i=0;i<array.size();i++)
            st.insert(array[i]);
            
        for(int i=1;i<=n;i++)
        {
            if(st.find(i)==st.end())    
                return i;
        }
        return -1;
    }
};