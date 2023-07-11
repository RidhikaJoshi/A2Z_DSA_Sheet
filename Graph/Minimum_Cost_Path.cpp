/*
Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 

Note: It is assumed that negative cost cycles do not exist in the input matrix.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dist(r,vector<int>(c,1e9));
        dist[0][0]=grid[0][0];
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({dist[0][0],{0,0}});
        while(pq.size()!=0)
        {
            int cost=pq.top().first;
            int r1=pq.top().second.first;
            int c1=pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++)
            {
                int nr=r1+delr[k];
                int nc=c1+delc[k];
                if(nr>=0 && nr <r && nc>=0 && nc<c)
                {
                        if(dist[nr][nc]>cost+grid[nr][nc])
                        {
                            dist[nr][nc]=cost+grid[nr][nc];
                            pq.push({dist[nr][nc],{nr,nc}});
                        }
                }
            }
        }
        return dist[r-1][c-1];
        
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>>grid(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution s;
    int res=s.minimumCostPath(grid);
    cout << res << endl;
    return 0;
}