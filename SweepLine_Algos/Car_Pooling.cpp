/*
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> ans(1001, 0);
        for (int i = 0; i < trips.size(); i++)
        {
            int x = trips[i][0];
            int y = trips[i][1];
            int z = trips[i][2];
            ans[y] += x;
            ans[z] -= x;
        }
        int sum = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            sum += ans[i];
            if (sum > capacity)
                return false;
        }
        return true;
    }
};