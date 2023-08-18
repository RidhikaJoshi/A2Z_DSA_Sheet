/*
There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        set<pair<int,int>>st;
        vector<int>deg(n,0);
        int max=-1,secmax=-1;
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            deg[u]++;
            deg[v]++;
            st.insert({u,v});
        }
        for(int i=0;i<n;i++)
        {
            if(deg[i]>max)
            {
                secmax=max;
                max=deg[i];
            }
            else if(deg[i]<max && deg[i]>secmax)
            {
                secmax=deg[i];
            }
        }
        vector<int>m,scm;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==max)
                m.push_back(i);
            if(deg[i]==secmax)
                scm.push_back(i);
        }
        int res=-1;
        for(int i=0;i<m.size();i++)
        {
           
            for(int j=i+1;j<m.size();j++)
            {
                 int count=0;
                if(st.find({m[i],m[j]})==st.end() && st.find({m[j],m[i]})==st.end())
                    count=deg[m[i]]+deg[m[j]];
                else
                     count=deg[m[i]]+deg[m[j]]-1;

                if(count>res)
                    res=count;
            }
        }
        for(int i=0;i<m.size();i++)
        {
            for(int j=0;j<scm.size();j++)
            {
                int count=0;
                if(st.find({m[i],scm[j]})==st.end() && st.find({scm[j],m[i]})==st.end())
                    count=deg[m[i]]+deg[scm[j]];
                else
                     count=deg[m[i]]+deg[scm[j]]-1;

                if(count>res)
                    res=count;
            }
        }
        return res;

        
    }
};