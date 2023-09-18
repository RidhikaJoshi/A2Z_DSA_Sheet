/*You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.*/

#include <bits/stdc++.h>
using namespace std;

// Naive Solution
// Time=O(N*N)+ O(NlogN)+O(K);
// Space =O(N)+O(K);

class Solution
{
public:
    static bool mycmp(pair<int, int> a, pair<int, int> b)
    {
        if (a.first > b.first)
            return true;
        else if (b.first > a.first)
            return false;
        else
            return a.second > b.second;
    }
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> count;
        for (int i = 0; i < mat.size(); i++)
        {
            int c = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                    c++;
                else
                    break;
            }
            count.push_back({c, i});
        }
        sort(count.begin(), count.end(), mycmp);
        vector<int> res;
        for (int i = mat.size() - 1; res.size() != k; i--)
            res.push_back(count[i].second);

        return res;
    }
};

// Optimised Solution
// Time=O(NlogN)+ O(NlogN)+O(K);
// Space =O(N)+O(K);
class Solution
{
public:
    static bool mycmp(pair<int, int> a, pair<int, int> b)
    {
        if (a.first > b.first)
            return true;
        else if (b.first > a.first)
            return false;
        else
            return a.second > b.second;
    }
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> count;
        for (int i = 0; i < mat.size(); i++)
        {
            int low = 0, high = mat[0].size() - 1, ans = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (mat[i][mid] == 1)
                {
                    ans = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            if (ans == -1)
                count.push_back({0, i});
            else
                count.push_back({ans + 1, i});
        }
        sort(count.begin(), count.end(), mycmp);
        vector<int> res;
        for (int i = mat.size() - 1; res.size() != k; i--)
            res.push_back(count[i].second);

        return res;
    }
};