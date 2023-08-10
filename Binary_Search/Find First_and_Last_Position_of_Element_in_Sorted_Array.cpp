/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
#include<bits/stdc++.h>
using namespace std;
// Intuition: Using the concept of lower bound to get the first ocurrence of target element . we need to search only in the left part of the array
// in order to get the last position we used the concept of upper bound .

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int low=0,high=nums.size()-1;
        int f=-1,c=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                f=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                c=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return {f,c};
    }
};