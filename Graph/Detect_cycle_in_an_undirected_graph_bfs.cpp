/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
*/
#include<bits/stdc++.h>
using namespace std;

bool bfs(int src,vector<int>adj[],vector<int>&vis)
{
       vis[src]=1;
       queue<pair<int,int>>q;
       q.push({src,-1});
       while(q.size()!=0)
        {
            int x=q.front().first;
            int p=q.front().second;
            q.pop();
            for(auto it:adj[x])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                   q.push({it,x});
                }
                else if(it!=p)
                    return true;
                    
            }
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
                if(bfs(i,adj,vis)==true)
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