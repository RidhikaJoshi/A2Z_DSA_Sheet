/*Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.

Constraints:

 1 <= nums.length <= 1000
 1 <= sum(nums[i].length) <= 1000
 1 <= nums[i][j] <= 1000
 All the values of nums[i] are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        int n = nums.size();
        vector<int> res;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                m[nums[i][j]]++;
            }
        }
        for (auto it : m)
        {
            if (it.second == nums.size())
                res.push_back(it.first);
        }
        return res;
    }
};