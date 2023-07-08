/*
Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        int r=grid.size();
        int c=grid[0].size();
        int sr=source.first;
        int sc=source.second;
        int dr=destination.first;
        int dc=destination.second;
        // vector<vector<int>>vis(r,vector<int>(c,0));
        vector<vector<int>>dist(r,vector<int>(c,1e9));
        dist[sr][sc]=0;
        queue<pair<int,int>>q;
        q.push({sr,sc});
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
                    if(grid[nr][nc]!=0)
                    {
                        if(dist[nr][nc]>dist[r1][c1]+1)
                        {
                            dist[nr][nc]=dist[r1][c1]+1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        if(dist[dr][dc]!=1e9)
            return dist[dr][dc];
        else
            return -1;
        
    }
};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];
        }
    }
    pair<int,int>source,destination;
    cin >> source.first >> source.second;
    cin >> destination.first >> destination.second;
    Solution s;
    int res=s.shortestPath(grid,source,destination);
    cout << res << endl;
    return 0;
}