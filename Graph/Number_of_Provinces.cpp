/*
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int src,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[src]=1;
        for(int i=0;i<adj[src].size();i++)
        {
            if(vis[i]==0 && adj[src][i]==1) 
                dfs(i,adj,vis);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        int count=0;
       vector<int>vis(V,0);
       for(int i=0;i<V;i++)
       {
           if(vis[i]==0)
           {
               count++;
               dfs(i,adj,vis);
           }
           
       }
       return count;
    }
};
int main()
{
    Solution s;
    int V,u,v;
    cin >> V ;
    vector<vector<int>> adj(V,vector<int>(V));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin >> adj[i][j];
        }
        
    }
    int ans=s. numProvinces(adj,V);
    cout << ans << endl;
    return 0;
}