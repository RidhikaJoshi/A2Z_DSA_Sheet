/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(vector<int>& weights,int mid)
    {
        int count=0,sum=0;
        for(int i=0;i<weights.size();i++)
        {
            if((weights[i]+sum)<=mid)
                sum+=weights[i];
            else
            {
                count++;
                sum=weights[i];
            }
        }
         count++;
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days)
    {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<weights.size();i++)
            high+=weights[i];
        //cout << low << " " << high << endl;;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int d=func(weights,mid);
            //cout << mid << " " << d<< endl;
            if(d<=days)
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