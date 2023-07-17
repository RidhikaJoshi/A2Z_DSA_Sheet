/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findparent(int u,int par[])
    {
        if(u==par[u])
            return u;

        return par[u]=findparent(par[u],par);
    }
    void union_find(int u,int v,int par[],int size[])
    {
        int ulp_u=findparent(u,par);
        int ulp_v=findparent(v,par);

        if(ulp_u==ulp_v)
            return ;

        else if(size[ulp_u]>size[ulp_v])
        {
            size[ulp_u]+=size[ulp_v];
            par[ulp_v]=ulp_u;
        }
        else if(size[ulp_u]<=size[ulp_v])
        {
            size[ulp_v]+=size[ulp_u];
            par[ulp_u]=ulp_v;

        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n=edges.size();
        int par[n+1],size[n+1];
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            size[i]=1;
        }
        int dr=0,dc=0;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(findparent(u,par)==findparent(v,par))
            {
                dr=u;dc=v;         
            }

            else
                union_find(u,v,par,size);
        }
        vector<int>res;
        res.push_back(dr);
        res.push_back(dc);
        return res;
        
    }
};