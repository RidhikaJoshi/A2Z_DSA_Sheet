/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
     {
         vector<vector<pair<int,int>>>adj(N);
         for(int i=0;i<M;i++)
         {
             int u=edges[i][0];
             int v=edges[i][1];
             int wt=edges[i][2];
             adj[u].push_back({v,wt});
         }
         vector<int>dist(N,1e9);
         dist[0]=0;
         queue<pair<int,int>>q;
         q.push({0,0});
         while(q.size()!=0)
         {
             int x=q.front().first;
             int y=q.front().second;
             q.pop();
             for(auto it:adj[x])
             {
                if(dist[it.first]>y+it.second)
                {
                    dist[it.first]=y+it.second;
                    q.push({it.first,dist[it.first]});
                }
             }
         }
         for(int i=0;i<N;i++)
         {
             if(dist[i]==1e9)
                dist[i]=-1;
         }
         return dist;
        
    }
};
int main()
{
    int N,M;
    cin >> N  >> M;
    vector<vector<int>>edges;
    for(int i=0;i<M;i++)
    {
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({u,v,wt});
    }
    Solution s;
    vector<int>res=s.shortestPath(N,M,edges);
    for(int i=0;i<N;i++)
    {
        cout << res[i] << " " ;
    }
return 0;
}
