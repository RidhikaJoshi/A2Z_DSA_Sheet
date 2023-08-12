/*
To make one bouquet we need K adjacent flowers from the garden. Here the garden consists of N different flowers, the ith flower will bloom in the bloomDay[i]. Each flower can be used inside only one bouquets. We have to find the minimum number of days need to wait to make M bouquets from the garden. If we cannot make m bouquets, then return -1.

The first line of input contains two integers M and K.
The second line contains N space-separated integers of bloomDay[i] array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int M, int K, vector<int> &bloomDay)
    {
        int high=*max_element(bloomDay.begin(),bloomDay.end()); 
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int count=0,a=0;
            for(int i=0;i<bloomDay.size();i++)
            {
                if(bloomDay[i]<=mid)
                    count++;
                else
                {
                   a+=count/K;
                   count=0;
                }
            }
             a+=count/K;
             if(a>=M)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    
    }
};