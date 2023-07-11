/*
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

A Minimum Spanning Tree is a tree with n nodes and n-1 edges and all nodes are reachable from any given node.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       
        vector<int>dist(V,1e9);
        dist[0]=0;
        vector<int>vis(V,0);
        vector<int>parent(V,0);
        int res=0;
        for(int i=0;i<V;i++)
        {
            int u=-1;
            for(int j=0;j<V;j++)
            {
                if(vis[j]==0 && (u==-1 || dist[j]<dist[u]))
                    u=j;
            }
            vis[u]=1;
            res+=dist[u];
            for(auto it:adj[u])
            {
                if(vis[it[0]]==0)
                {
                    int wt=it[1];
                    if(dist[it[0]]>wt)
                    {
                        dist[it[0]]=wt;
                        parent[it[0]]=u;
                    }
                }
            }
        }
        return res;
        
    }
};

int main()
{
    int V,E;
    cin >> V >> E;
    vector<vector<int>>adj[V];
    for(int i=0;i<E;i++)
    {
        int u,v,wt;
        cin >> u >> v >> wt;
        vector<int>t1;
        t1.push_back(u);
        t1.push_back(wt);
        adj[v].push_back(t1);
        vector<int>t2;
        t2.push_back(v);
        t2.push_back(wt);
        adj[u].push_back(t2);
    }
    Solution s;
    cout <<  s.spanningTree(V,adj) << endl;
    return 0;
}