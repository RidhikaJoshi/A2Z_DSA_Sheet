/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/
// Intuition: if target already present then using binary search we need to just find out the index of target element
// if target is not present then upper bound of target will be the position for the insertion of that target element

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int low=0,high=nums.size()-1,ans=nums.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
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