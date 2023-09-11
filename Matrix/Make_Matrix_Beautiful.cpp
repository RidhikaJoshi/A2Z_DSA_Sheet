/*
A beautiful matrix is a matrix in which the sum of elements in each row and column is equal. Given a square matrix of size NxN. Find the minimum number of operation(s) that are required to make the matrix beautiful. In one operation you can increment the value of any one cell by 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find minimum number of operations that are required
    // to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> matrix, int n)
    {
        vector<int> ans1, ans2;
        for (int i = 0; i < n; i++)
        {
            int r = 0;
            for (int j = 0; j < n; j++)
            {
                r += matrix[i][j];
            }
            int c = 0;
            for (int j = 0; j < n; j++)
            {
                c += matrix[j][i];
            }

            ans1.push_back(r);
            ans2.push_back(c);
        }
        int mx1 = *max_element(ans1.begin(), ans1.end());
        int mx2 = *max_element(ans2.begin(), ans2.end());
        mx1 = max(mx1, mx2);
        int res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++)
        {
            res1 += abs(ans1[i] - mx1);
        }
        return res1;
    }
};