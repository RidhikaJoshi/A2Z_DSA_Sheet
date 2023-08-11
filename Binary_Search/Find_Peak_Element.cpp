/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1)
            return 0;
            // checking the edge cases here
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;
        int low=1,high=n-2;
        // triming down of search space to avoid redundancy and to increase code readability
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
                // greater element side will only contain the peak element
            else if(nums[mid-1]>nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
        
    }
};