/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.


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
        else
        {
             size[ulp_v]+=size[ulp_u];
            par[ulp_u]=ulp_v;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        int par[n],size[n];
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            size[i]=1;
        }
        int redunt=0;
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];

            if(findparent(u,par)==findparent(v,par))
                redunt++;

            
            union_find(u,v,par,size);
        
        }
        int components=0;
        for(int i=0;i<n;i++)
        {
            if(par[i]==i)
                components++;
        }
        if(redunt>=(components-1))
            return components-1;
        return -1;
        
    }
};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> connections;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        connections.push_back({u,v});
    }
    Solution s;
    cout << s.makeConnected(n,connections) << endl;;
    return 0;

}