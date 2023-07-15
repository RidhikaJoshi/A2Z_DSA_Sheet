/*
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int findparent(int i,int par[])
    {
        if(i==par[i])
            return i;
            
            
        return par[i]=findparent(par[i],par);
    }
    void union_find(int u,int v,int par[],int size[])
    {
        int ulp_u=findparent(u,par);
        int ulp_v=findparent(v,par);
        if(ulp_u==ulp_v)
            return ;
            
            
        else if(size[ulp_u]<size[ulp_v])
        {
            size[ulp_v]+=size[ulp_u];
            par[ulp_u]=ulp_v;
        }
        else
        {
            size[ulp_u]+=size[ulp_v];
            par[ulp_v]=ulp_u;
        }
    }
    int numProvinces(vector<vector<int>> adj, int V)
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
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)
                {
                    if(findparent(i,par)!=findparent(j,par))
                        union_find(i,j,par,size);
                }
            }
        }
        unordered_set<int>st;
        for(int i=0;i<V;i++)
        {
            st.insert(findparent(i,par));
        }
        return st.size();
        
    }
};

int main()
{
    int V;
    cin >> V;
    vector<vector<int>>adj(V,vector<int>(V));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin >> adj[i][j];
        }
    }
    Solution s;
   cout <<  s.numProvinces(adj,V) << endl;;
   return 0;
}