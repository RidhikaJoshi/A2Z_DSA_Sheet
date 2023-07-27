/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
       unordered_map<int,int>m;
       int mx=0,pre=0;
       for(int i=0;i<n;i++)
       {
           pre+=A[i];
           if(pre==0)
                mx=i+1;
           if(m.find(pre)==m.end())
                m[pre]=i;
            else if(m.find(pre)!=m.end())
                mx=max(mx,i-m[pre]);
       }
       return mx;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int>A(n);
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }

    
    Solution s;
    cout << s.maxLen(A,n) << endl;;
    return 0;
}