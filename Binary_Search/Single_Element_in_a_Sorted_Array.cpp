/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

/*
The index sequence of the duplicate numbers in the left half is always (even, odd). That means one of the following conditions will be satisfied if we are in the left half:
If the current index is even, the element at the next odd index will be the same as the current element.
Similarly, If the current index is odd, the element at the preceding even index will be the same as the current element.
The index sequence of the duplicate numbers in the right half is always (odd, even). That means one of the following conditions will be satisfied if we are in the right half:
If the current index is even, the element at the preceding odd index will be the same as the current element.
Similarly, If the current index is odd, the element at the next even index will be the same as the current element.
*/

#include<bits/stdc++.h>
using namespace std;
// Intuition: Since all other elements present in the array is twice only one element is single.
// so by the index of the mid we cal calculate the posn of that req element
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(nums[0]!=nums[1])    
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        int low=1,high=nums.size()-2;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            else if(nums[mid]==nums[mid-1])
            {
                if(mid%2==0)
                    high=mid-1;
                else
                    low=mid+1;
            }
            else
            {
                if(mid%2==0)
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};