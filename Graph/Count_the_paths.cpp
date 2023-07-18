/*
Given a directed acyclic graph(DAG) with n nodes labeled from 0 to n-1. Given edges, s and d ,count the number of ways to reach from s to d.There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1].
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
   void dfs(vector<vector<int>>adj,int s,int d,vector<int>&vis,vector<int>&pathvis
    ,int &count)
    {
        vis[s]=1;
        pathvis[s]=1;
        for(auto it:adj[s])
        {
            if( pathvis[it]==0)
            {
                if(it==d)
                {
                    count++;
                    pathvis[s]=0;
                    return;
                }
                dfs(adj,it,d,vis,pathvis,count);
            }
            
        }
pathvis[s]=0;
        return ;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d)
	{
	    vector<vector<int>>adj(n);
	    for(int i=0;i<edges.size();i++)
	    {
	        int u=edges[i][0];
	        int v=edges[i][1];
	        adj[u].push_back(v);
	    }
	    vector<int>vis(n,0);
	    vector<int>pathvis(n,0);
	    if(s==d)
	        return 1;
	    int count=0;
	    dfs(adj,s,d,vis,pathvis,count);
	    return count;

	}
};