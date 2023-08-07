/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/

#include<bits/stdc++.h>
using namespace  std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int,int>m;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                m[nums2[i]]=-1;
            }
            else if(st.size()!=0 && st.top()>nums2[i])
            {
                m[nums2[i]]=st.top();
            }
            else if(st.size()!=0 && st.top()<nums2[i])
            {
                while(st.size()!=0 && st.top()<nums2[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                    m[nums2[i]]=-1;
                else
                    m[nums2[i]]=st.top();
            }

            st.push(nums2[i]);
        }
        vector<int>res;
        for(int i=0;i<nums1.size();i++)
        {
            res.push_back(m[nums1[i]]);
        }
        return res;
        
    }
};