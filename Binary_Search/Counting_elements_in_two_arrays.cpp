/*
Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. For each element in arr1[] count elements less than or equal to it in array arr2[].
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        sort(arr2,arr2+n);
        vector<int>res;
        for(int i=0;i<m;i++)
        {
            int x=arr1[i],ans=-1;
            int low=0,high=n-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(arr2[mid]>x)
                {
                    high=mid-1;
                }
                else
                {
                    ans=mid;
                    low=mid+1;
                }
            }
            res.push_back(ans+1);
            
        }
        return res;
            
    }
};