/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int func(vector<int>& nums,int mid)
    {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%mid==0)
                count+=nums[i]/mid;
            else
                count+=nums[i]/mid+1;
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int cal=func(nums,mid);
            if(cal<=threshold)
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