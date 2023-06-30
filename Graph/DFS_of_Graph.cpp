/*
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use a recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.
*/

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