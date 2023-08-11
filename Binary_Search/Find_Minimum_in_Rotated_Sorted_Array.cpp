/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/

#include<bits/stdc++.h>
using namespace std;
// Intuition: we are just trimming down our search space. Firstly we find out the sorted part
// The sorted part may or may not contain the answer
// so we take the min from the sorted part and again search in an unsorted part. 
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int low=0,high=nums.size()-1;
        int ans=1e9;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[mid])
            {
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else 
            {
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
        
    }
};