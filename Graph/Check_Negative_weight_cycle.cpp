/*
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    vector<int>dist(n,1e9);
	    for(int i=0;i<n-1;i++)
	    {
	        for(int j=0;j<edges.size();j++)
	        {
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            if(dist[v]>dist[u]+wt)
	                dist[v]=dist[u]+wt;
	        }
	    }
	   for(int j=0;j<edges.size();j++)
	   {
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            if(dist[v]>dist[u]+wt)
	                return 1;
	   }
	    return 0;
	    
	}
};

int main()
{
    int n,e,u,v,wt;
    cin >> n >> e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++)
    {
        cin >> u >> v >> wt;
        edges.push_back({u,v,wt});
    }
    Solution s;
    cout << s.isNegativeWeightCycle(n,edges) << endl;
    return 0;
}