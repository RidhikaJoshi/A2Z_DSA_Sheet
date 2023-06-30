/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
*/
#include<bits/stdc++.h>
using namespace std;
bool dfs(int src,vector<int>adj[],vector<int>&vis,int p)
{
        vis[src]=1;
        for(auto it:adj[src])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,src)==true)
                    return true;
            }
            else if(it!=p)
                return true;
        }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,adj,vis,-1)==true)
                    return true;
            }
        }
       return false;
}
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
    bool ans=isCycle(V,adj);
    if(ans)
        cout << "1" << endl;
    else    
        cout << "0" << endl;
return 0;

}