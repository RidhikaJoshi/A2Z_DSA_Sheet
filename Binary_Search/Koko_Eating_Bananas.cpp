/*
Given N piles of bananas, the ith pile has piles[i] bananas and H hours time until guards return (N <= H). Find the minimum (S) bananas to eat per hour such that Koko can eat all the bananas within H hours. Each hour, Koko chooses some pile of bananas and eats S bananas from that pile. If the pile has less than S bananas, then she consumes all of them, and wont eat any more bananas during that hour. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:


    int Solve(int N, vector<int>& piles, int H)
    {
        int ans=0;
        sort(piles.begin(),piles.end());
        int low=1,high=piles[N-1];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int count=0;
            for(int i=0;i<N;i++)
            {
                if(piles[i]%mid==0)
                    count=count+(piles[i]/mid);
                else
                    count=count+(piles[i]/mid)+1;
            }
            if(count>H)
                low=mid+1;
            else if(count<=H)
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }

    
};