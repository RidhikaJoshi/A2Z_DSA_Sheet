/*
You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
    {
        vector<vector<int>>adj(N);
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dist(N,-1);
        dist[src]=0;
        queue<int>q;
        q.push(src);
        vector<int>vis(N,0);
        vis[src]=1;
        while(q.size()!=0)
        {
            int x=q.front();
            q.pop();
            for(auto it:adj[x])
            {
                if(vis[it]==0)
                {
                    dist[it]=dist[x]+1;
                    vis[it]=1;
                    q.push(it);
                }
            }
            
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
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }
    int src;
    cin >> src;
    Solution s;
    vector<int>res=s.shortestPath(edges,N,M,src);
    for(int i=0;i<N;i++)
    {
        cout << res[i] << " " ;
    }
return 0;
}