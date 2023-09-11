/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {

            int low = 0, high = n - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return false;
    }
};