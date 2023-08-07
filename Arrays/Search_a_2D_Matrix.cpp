/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int r=matrix.size();
        int c=matrix[0].size();
        int i=0,j=0;
        while(i<r && j<c)
        {
            if(matrix[i][j]==target)
                return true;
            else if((i+1)<r && matrix[i+1][j]<=target)
            {
                i=i+1;
            }
            else if((j+1)<c && matrix[i][j+1]<=target)
            {
                j=j+1;
            }
            else
                return false;
        }
        return false;
        
    }
};