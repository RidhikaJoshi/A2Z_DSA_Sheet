/*Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom)
        {
            for (int j = left; j <= right; j++)
            {
                res[top][j] = i;
                i++;
            }
            top++;
            for (int j = top; j <= bottom; j++)
            {
                res[j][right] = i;
                i++;
            }
            right--;
            if (top <= bottom)
            {
                for (int j = right; j >= left; j--)
                {
                    res[bottom][j] = i;
                    i++;
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int j = bottom; j >= top; j--)
                {
                    res[j][left] = i;
                    i++;
                }
                left++;
            }
        }
        return res;
    }
};