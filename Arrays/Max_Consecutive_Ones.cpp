/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    { 

        int count=0,max=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                count++;
            else
            {
                if(count>max)
                    max=count;
                count=0;
            }
        }
        if(count>max)
            max=count;

        return max;
        
    }

    
};