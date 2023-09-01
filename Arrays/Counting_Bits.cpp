/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.*/

#include <bits/stdc++.h>
using namespace std;
// 1st approach
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            res.push_back(__builtin_popcount(i));
        }
        return res;
    }
};