/*
There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(q.size()!=0)
        {
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>K)
                continue;
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int extracost=it.second;
                if(cost+extracost<dist[adjnode] && stops<=K)
                {
                    dist[adjnode]=cost+extracost;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
            
        }
        if(dist[dst]==1e9)
            return -1;
        else
            return dist[dst];
       
    }
};

int main()
{
    int v,e,u,x,wt;
    cin >> v >> e ;
    vector<vector<int>>flights;
    for(int i=0;i<e;i++)
    {
        cin >> u >> x >> wt;
        flights.push_back({u,x,wt});
    }
    int src,dst,K;
    cin >> src >> dst >> K;
    Solution s;
    int res=s.CheapestFLight(v,flights,src,dst,K);
    cout << res << endl;
    return 0;
}