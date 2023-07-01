/*
Given a matrix mat of size N x M where every element is either O or X.
Replace all O with X that are surrounded by X.
A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, just above, just left and just right of it.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>>res(n,vector<char>(m));
       vector<vector<int>>vis(n,vector<int>(m,0));
       queue<pair<int,int>>q;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(mat[i][j]=='O' && vis[i][j]==0)
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
               if(nr>=0 && nc>=0 && nr<n && nc<m)
               {
                   if(mat[nr][nc]=='O' && vis[nr][nc]==0)
                    {
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
               }
           }
       }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(vis[i][j]==1 && mat[i][j]=='O')
                    res[i][j]='O';
                else
                    res[i][j]='X';
           }
       }
       return res;
    }
};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>>mat(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution s;
    vector<vector<char>>res=s.fill(n,m,mat);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}