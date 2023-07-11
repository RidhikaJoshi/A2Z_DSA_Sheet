/*
Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
       vector<vector<int>>dist(N,vector<int>(M,1e9));
       queue<pair<int,int>>q;
       q.push({0,0});
       dist[0][0]=0;
       int delr[4]={-1,0,1,0};
       int delc[4]={0,1,0,-1};
       if(X==0 && Y==0)
        return 0;
       while(q.size()!=0)
       {
           int r1=q.front().first;
           int c1=q.front().second;
           q.pop();
           for(int k=0;k<4;k++)
           {
               int nr=r1+delr[k];
               int nc=c1+delc[k];
               if(nr>=0 && nr<N && nc>=0 && nc<M)
               {
                   if(A[nr][nc]==1)
                   {
                       if(dist[nr][nc]>dist[r1][c1]+1)
                       {
                           dist[nr][nc]=dist[r1][c1]+1;
                           q.push({nr,nc});
                           if(nr==X && nc==Y)
                            return dist[nr][nc];
                       }
                   }
               }
           }
       }
 
       return -1;
    }
};

int main()
{
    int N,M,X,Y;
    cin >> N >> M;
    vector<vector<int>>A(N,vector<int>(M));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> A[i][j];
        }
    }
    cin  >> X >> Y;
    Solution s;
    cout << s.shortestDistance(N,M,A,X,Y) << endl;
    return 0;
}