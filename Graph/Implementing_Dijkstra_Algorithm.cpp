/*
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V,1e9);
        vector<int>vis(V,0);
        dist[S]=0;
        for(int i=0;i<V;i++)
        {
            int u=-1;
            for(int j=0;j<V;j++)
            {
                if(vis[j]==0 && (u==-1 || dist[j]<dist[u]))
                    u=j;
            }
            vis[u]=1;
            for(auto it:adj[u])
            {
                int x=it[0];
                int y=it[1];
                if(dist[x]>dist[u]+y)
                {
                    dist[x]=dist[u]+y;
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(dist[i]==1e9)
                    dist[i]=-1;
        }
        return dist;
    }
};

