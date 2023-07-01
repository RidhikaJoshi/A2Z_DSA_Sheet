/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(int src,vector<int>adj[],vector<int>&vis,vector<int>&pathvis)
    {
        vis[src]=1;
        pathvis[src]=1;
        for(auto it:adj[src])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,pathvis)==true)
                    return true;
            }
            if(pathvis[it]==1)
                return true;
        }
        pathvis[src]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int>pathvis(V,0);
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
                if(dfs(i,adj,vis,pathvis)==true)
                    return true;
        }
        return false;
       
    }
};

int main()
{
    int v,e;
    cin >> v >> e;
    vector<int>adj[v];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Solution s;
    if(s.isCyclic(v,adj)==true)
        cout << "1" << endl;
    else    
        cout << "0" << endl;
}