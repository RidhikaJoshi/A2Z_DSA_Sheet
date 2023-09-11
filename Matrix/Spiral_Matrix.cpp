/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int r=matrix.size(),c=matrix[0].size();
        int top=0,bottom=r-1,left=0,right=c-1;
        vector<int>res;
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        
        }
        return res;
        
    }
};