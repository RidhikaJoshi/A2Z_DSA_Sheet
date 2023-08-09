/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // using time complexity-O(NlogN)
    // space complexity-O(N)
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto it:m)
        {
            pq.push({it.second,it.first});
        }
        vector<int>res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }
};