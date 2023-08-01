/*
Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 
*/

#include<bits/stdc++.h>
using namespace  std;


class Solution{
    //Function to find the leaders in the array.
    public:
    //using stack approach
    vector<int> leaders(int a[], int n)
    {
        vector<int>res;
       stack<int>st;
       for(int i=n-1;i>=0;i--)
       {
           if(st.size()==0)
                res.push_back(-1);
            else if(st.top()<=a[i])
            {
                while(st.size()!=0 && st.top()<=a[i])
                    st.pop();
                    
                if(st.size()==0)
                    res.push_back(-1);
                else
                    res.push_back(st.top());
            }
            else
                res.push_back(st.top());
                
            st.push(a[i]);
                
       }
       reverse(res.begin(),res.end());
       vector<int>ans;
       for(int i=0;i<n;i++)
       {
           if(res[i]==-1)
            ans.push_back(a[i]);
       }
        return ans;
    }
    //Just maintaing the max in the right side of every element to claculate the leaders
    vector<int> leaders(int a[], int n)
    {
        vector<int>res;
        int max=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>=max)
            {
                res.push_back(a[i]);
                max=a[i];
            }
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};