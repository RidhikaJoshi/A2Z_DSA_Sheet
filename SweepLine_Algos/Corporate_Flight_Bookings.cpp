/*
There are n flights that are labeled from 1 to n.

You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.


*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> res(n + 1, 0);
        for (int i = 0; i < bookings.size(); i++)
        {
            int x = bookings[i][0];
            int y = bookings[i][1];
            int z = bookings[i][2];
            res[x - 1] += z;
            res[y] -= z;
        }
        vector<int> ans(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += res[i];
            ans[i] = sum;
        }
        return ans;
    }
};