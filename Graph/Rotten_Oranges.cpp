/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 If not possible returns -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue<pair<int,int>>q;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        int count=0;
        while(q.size()!=0)
        {
            int s=q.size(),d=-1;
            for(int i=0;i<s;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int nr=x+delr[k];
                    int nc=y+delc[k];
                    if(nr>=0 && nr<r && nc>=0 && nc<c)
                    {
                        if(grid[nr][nc]==1)
                        {
                            grid[nr][nc]=2;
                            q.push({nr,nc});
                            d=1;
                        }
                    }
                }
            }
            if(d==1)
                count++;
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return count;
       
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
            cin >>grid[i][j];
        }
    }
    int ans;
    ans=s.orangesRotting(grid);
    cout << ans << endl;
    return 0;
}