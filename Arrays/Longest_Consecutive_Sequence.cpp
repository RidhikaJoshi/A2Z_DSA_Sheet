/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if(nums.size()==0)
            return 0;
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }

        int count=0,max=-1,x;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]-1)==st.end())
            {
                count=1,x=nums[i];
                while(st.find(x+1)!=st.end())
                {
                    x+=1;
                    count++;
                }
                if(count>max)
                    max=count;
            }
         
        }
        return max;
        
    }
};