/*
Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.

Note: There are only a single source and a single destination.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int r=grid.size();
        int c=grid[0].size();
        int sr,sc,dr,dc;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    sr=i;
                    sc=j;
                    break;
                }
            }
        }

        
          for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                {
                    dr=i;
                    dc=j;
                    break;
                }
            }
        }


        vector<vector<int>>vis(r,vector<int>(c,0));
        queue<pair<int,int>>q;
	   int delr[4]={-1,0,1,0};
	   int delc[4]={0,1,0,-1};
        q.push({sr,sc});
        vis[sr][sc]=1;


        while(q.size()!=0)
        {
            int i1=q.front().first;
            int j1=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nr=i1+delr[k];
                int nc=j1+delc[k];
                if(nr>=0 && nr<r && nc>=0 && nc<c)
                {
                    if(nr==dr && nc==dc)
                        return true;
                    if(grid[nr][nc]==3 && vis[nr][nc]==0)
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                        
                    }
                }
            }
            
        }


        if(vis[dr][dc]==0)
            return false;
        return true;
    }
};

int main()
{
    int r;
    cin >> r;
    vector<vector<int>>grid(r,vector<int>(r));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution s;
    if(s.is_Possible(grid))
    cout << "1" << endl;
    else
        cout << "0 "<< endl;
    return 0;
}