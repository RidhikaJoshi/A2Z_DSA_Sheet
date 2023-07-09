/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int src,vector<int>adj[],vector<int>&vis,vector<int>&pathvis,vector<int>&res)
    {
        vis[src]=1;
        pathvis[src]=1;
        for(auto it:adj[src])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,pathvis,res)==true)
                    return true;
            }
            else if(pathvis[it])
                return true;
        }
        pathvis[src]=0;
        res.push_back(src);
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int>res;
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj,vis,pathvis,res);
            }
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};

int main()
{
    int v,e,x,y;
    cin >> v >> e;
    vector<int>adj[v];
    for(int i=0;i<e;i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    Solution s;
    vector<int>res=s.eventualSafeNodes(v,adj);
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << " " ;
    }
    return 0;
}