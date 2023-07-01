/*
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>>&grid)
	{
	   queue<pair<int,int>>q;
	   int r=grid.size();
	   int c=grid[0].size();
	   vector<vector<int>>res(r,vector<int>(c,0));
	   vector<vector<int>>vis(r,vector<int>(c,0));
	   for(int i=0;i<r;i++)
	   {
	       for(int j=0;j<c;j++)
	       {
	           if(grid[i][j]==1)
	           {
	              vis[i][j]=1;
	              q.push({i,j});
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
	           if(nr>=0 && nr<r && nc>=0 && nc<c)
	           {
	               if(vis[nr][nc]==0 && grid[nr][nc]==0)
	               {
	                    res[nr][nc]=res[r1][c1]+1;
	                    vis[nr][nc]=1;
	                    q.push({nr,nc});
	               }
	           }
	       }
	   }
	   return res;
	}
};
int main()
{
    Solution s;
    int r,c;
    cin >> r >> c;
    vector<vector<int>>grid(r,vector<int>(c));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>>res=s.nearest(grid);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}