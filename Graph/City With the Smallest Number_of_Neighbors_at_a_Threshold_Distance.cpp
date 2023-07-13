/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distance Threshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance, If there are multiple such cities, our answer will be the city with the greatest number.

Note: that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold)
    {
          vector<vector<int>>adj(n,vector<int>(n,1e9));
          for(int i=0;i<n;i++)
          {
              adj[i][i]=0;
          }
          for(int i=0;i<m;i++)
          {
              int u=edges[i][0];
              int v=edges[i][1];
              int wt=edges[i][2];
              adj[u][v]=wt;
              adj[v][u]=wt;
          }
          for(int k=0;k<n;k++)
          {
              for(int i=0;i<n;i++)
              {
                  for(int j=0;j<n;j++)
                  {
                      adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                  }
              }
          }
          int city=-1,max=1e9;
          for(int i=0;i<n;i++)
          {
              int count=0;
              for(int j=0;j<n;j++)
              {
                  if(adj[i][j]<=distanceThreshold)
                    count++;
              }
              if(count<=max)
                {
                    max=count;
                    city=i;
                }
          }
          return city;
    }
};

int main()

{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({u,v,wt});
    }
    int dit;
    cin >> dit;
    Solution s;
    int ans=s.findCity(n,m,edges,dit);
    cout << ans << endl;
    return 0;
}