/*
Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    // time-O(N) space =O(N);
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
       unordered_map<long long,long long >m;
       long long p=0;
       for(int i=0;i<n;i++)
       {
           p+=arr[i];
           if(p==s)
           {
               return {1,i+1};
           }
            else if(m.find(p-s)!=m.end())
           {
               return {m[p-s]+1,i+1};
           }
           if(m.find(p)==m.end())
                m[p]=i+1;
       }
      return {-1};
    
    }
    // Uisng two pointer appraoch
    vector<int> subarraySumSliding(vector<int>arr, int n, long long s)
    {
        long long sum=0;
        int i=0,j=0;
        while(j<n)
        {
            sum+=arr[j];
            //cout << sum << endl;
            if(sum==s)
                return {i+1,j+1};
            else if(sum>s)
            {
                while(sum>s)
                {
                    sum-=arr[i];
                    i++;
                }
                if(sum==s && i<=j)
                    return {i+1,j+1};
                else if(sum<s)
                    j++;
            }
           else if(sum<s)
            j++;
                
        }
        return {-1};
    }
    

};