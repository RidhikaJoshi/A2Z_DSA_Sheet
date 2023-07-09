/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights)
    {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>>dist(r,vector<int>(c,1e9));
        queue<pair<int,int>>q;
        q.push({0,0});
        dist[0][0]=0;
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        while(q.size()!=0)
        {
            int r1=q.front().first;
            int c1=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nr=r1+delr[k];
                int nc=c1+delc[k];
                if(nr>=0 && nr<r && nc>=0 && nc<c)
                {
                    int m=abs(heights[r1][c1]-heights[nr][nc]);
                    int n=dist[r1][c1];
                    if(dist[nr][nc]>max(n,m))
                    {
                        dist[nr][nc]=max(n,m);
                        q.push({nr,nc});
                    }
                }
            }
            
        }
        return dist[r-1][c-1];
       
    }
};

int main()
{
    int r,c;
    cin >> r >> c;
    vector<vector<int>>heights(r,vector<int>(c));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> heights[i][j];
        }
    }
    Solution s;
    int res=s.MinimumEffort(heights);
    cout << res << endl;
    return 0;
}