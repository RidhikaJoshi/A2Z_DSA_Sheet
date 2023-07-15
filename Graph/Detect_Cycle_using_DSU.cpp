/*
Given an undirected graph with V nodes and E edges. The task is to check if there is any cycle in undirected graph.
Note: Solve the problem using disjoint set union(dsu).
*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    int findUparent(int u,int par[])
    {
        if(u==par[u])
            return u;
            
            
        return par[u]=findUparent(par[u],par);
    }
    
    bool union_find(int u,int v,int par[],int size[])
    {
        int ulp_u=findUparent(u,par);
        int ulp_v=findUparent(v,par);
        if(ulp_u==ulp_v)
            return true;
            
            
        else if(size[ulp_u]<size[ulp_v])
        {
            size[ulp_v]+=size[ulp_u];
            par[ulp_u]=ulp_v;
            return false;
        }
        else
        {
            size[ulp_u]+=size[ulp_v];
            par[ulp_v]=ulp_u;
            return false;
        }
    }
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    int par[V];
	    int size[V];
	    for(int i=0;i<V;i++)
	    {
	        par[i]=i;
	        size[i]=1;
	    }
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            if(it>i)
	            {
	                if(union_find(i,it,par,size))
	                    return true;
	                    
	               
	            }
	        }
	    }
	    return false;
	}
};

int main()
{
    int V,e;
    cin >> V >> e;
    vector<int>adj[V];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution s;
    if(s.detectCycle(V,adj))
        cout << "YES" << endl;
    else
        cout << "No" << endl;

    return 0;
}