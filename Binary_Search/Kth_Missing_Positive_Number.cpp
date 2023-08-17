/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Time-O(N),Space=O(1);
    int findKthPositive(vector<int>& arr, int k)
    {
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
                k++;
            else
                return k;
        }
        return k;
        
    }
    // using unordered set time=O(N)*2 ans Space =O(n);
    public:
    int findKthPositive(vector<int>& arr, int k)
    {
       unordered_set<int>st(arr.begin(),arr.end());
       int res;
       for(int i=1;i<=1e9;i++)
       {
           if(st.find(i)==st.end())
            k--;


            if(k==0)
                return i;
       }

        return -1;      
    }
};