/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int sr=KnightPos[0]-1;
	    int sc=KnightPos[1]-1;
	    int dr=TargetPos[0]-1;
	    int dc=TargetPos[1]-1;

	    vector<vector<int>>dist(N,vector<int>(N,1e9));
	    queue<pair<int,int>>q;
	    q.push({sr,sc});
	    dist[sr][sc]=0;
	    int delr[8]={-2,-2,-1,1,2,2,1,-1};
	    int delc[8]={-1,1,2,2,1,-1,-2,-2};
	    while(q.size()!=0)
	    {
	        int r1=q.front().first;
	        int c1=q.front().second;
	        q.pop();
	        for(int k=0;k<8;k++)
	        {
	            int nr=r1+delr[k];
	            int nc=c1+delc[k];
	            if(nr>=0 && nr<N && nc>=0 && nc<N)
	            {
	                
	                if(dist[nr][nc]>dist[r1][c1]+1)
	                {
	                    dist[nr][nc]=dist[r1][c1]+1;
	                    q.push({nr,nc});
	                }
	            }
	        }
	    }
	    if(dist[dr][dc]==1e9)
	        return -1;
	       else
	        return dist[dr][dc];
	}
};

int main()
{
    vector<int>KnightPos;
    vector<int>TargetPos;
    int N;
    cin >> N;
    int x,y;
    cin >> x >> y;
    KnightPos.push_back(x);
    KnightPos.push_back(y);
    cin >>  x >> y;
    TargetPos.push_back(x);
    TargetPos.push_back(y);
    Solution s;
    cout << s.minStepToReachTarget(KnightPos,TargetPos,N);
return 0;
}