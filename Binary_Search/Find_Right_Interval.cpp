/*You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<int> res;
        map<pair<int, int>, int> m;
        for (int i = 0; i < intervals.size(); i++)
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            m[{x, y}] = i;
        }
        vector<vector<int>> r = intervals;
        sort(r.begin(), r.end());
        for (int i = 0; i < intervals.size(); i++)
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            int low = 0, high = r.size() - 1;
            pair<int, int> z;
            z.first = -1;
            z.second = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                int u = r[mid][0];
                int v = r[mid][1];
                if (u >= y)
                {
                    z.first = u;
                    z.second = v;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            if (z.first == -1 && z.second == -1)
                res.push_back(-1);
            else
                res.push_back(m[{z.first, z.second}]);
        }
        return res;
    }
};