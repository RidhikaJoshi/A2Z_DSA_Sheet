/*
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use a recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int src,vector<int> adj[],vector<int>&vis,vector<int>&res)
    {
        vis[src]=1;
        res.push_back(src);
        for(auto it:adj[src])
        {
            if(vis[it]==0)
                 dfs(it,adj,vis,res);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int>res;
       vector<int>vis(V,0);
       for(int i=0;i<V;i++)
       {
           if(vis[i]==0)
            dfs(i,adj,vis,res);
       }
       return res;
    }
};
int main()
{
    int V,E,u,v;
    cin >> V >> E;
    vector<int>adj[V];
    for(int i=0;i<E;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution s;
    vector<int>ans;
    ans=s.dfsOfGraph(V,adj);
    for(int i=0;i<ans.size();i++)
      cout << ans[i] << " " ;

return 0;

}