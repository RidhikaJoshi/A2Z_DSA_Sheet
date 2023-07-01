/*
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0 || j==0 || i==r-1 || j==c-1)
                {
                    if(grid[i][j]==1 && vis[i][j]==0)
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
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
                if(nr>=0 && nc>=0 && nr<r && nc<c)
                {
                    if(grid[nr][nc]==1 && vis[nr][nc]==0)
                    {
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                    count++;
            }
        }
        return count;
       
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
    Solution s;
    int res=s.numberOfEnclaves(grid);
    cout << res << endl;
    return 0;
}