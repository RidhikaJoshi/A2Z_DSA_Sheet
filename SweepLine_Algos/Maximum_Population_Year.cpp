/*
You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<int> ans(101, 0);
        for (int i = 0; i < logs.size(); i++)
        {
            int x = logs[i][0];
            int y = logs[i][1];
            // cout << x<< " " << x-1950 << endl;
            ans[x - 1950] += 1;
            ans[y - 1950] -= 1;
        }
        int sum = 0, mx = -1e9, year = 0;
        for (int i = 0; i < 101; i++)
        {
            sum += ans[i];
            if (sum > mx)
            {
                mx = sum;
                year = i + 1950;
            }
        }
        return year;
    }
};