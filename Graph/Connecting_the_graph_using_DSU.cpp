/*
You are given a graph with n vertices and m edges.

You can remove one edge from anywhere and add that edge between any two vertices in one operation.

Find the minimum number of operations that will be required to make the graph connected.

If it is not possible to make the graph connected, return -1.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int findparent(int node,int par[])
    {
        if(node==par[node])
            return node;
            
        return par[node]=findparent(par[node],par);
    }
    void union_find(int u,int v,int par[],int size[],int &r)
    {
        int ulp_u=findparent(u,par);
        int ulp_v=findparent(v,par);
        
        if(ulp_u==ulp_v)
        {
            r++;
            return ;
        }
            
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
    int Solve(int n, vector<vector<int>>& edge)
    {
        int par[n];
        int size[n];
        int r=0;
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            size[i]=1;
        }
        for(int i=0;i<edge.size();i++)
        {
            union_find(edge[i][0],edge[i][1],par,size,r);
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(par[i]==i)
                count++;
        }
        if(r>=count-1)
            return count-1;
            
        return -1;
       
    }
};

int main()
{
    int n,e;
    cin >> n >> e;
    vector<vector<int>>edge;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin >> u >> v;
        edge.push_back({u,v});
    }
    Solution s;
    cout << s.Solve(n,edge) << endl;;
    return 0;
}