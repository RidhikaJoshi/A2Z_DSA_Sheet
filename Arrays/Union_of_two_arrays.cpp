/*
Given two arrays a[] and b[] of size n and m respectively. The task is to find the number of elements in the union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in the union.

Note : Elements are not necessarily distinct.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m) 
    {
        unordered_set<int>st;
        for(int i=0;i<n;i++)
            st.insert(a[i]);
        for(int i=0;i<m;i++)
            st.insert(b[i]);
            
        return st.size();
       
    }
};