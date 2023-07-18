/*
There are n houses and p water pipes in Geek Colony. Every house has at most one pipe going into it and at most one pipe going out of it. Geek needs to install pairs of tanks and taps in the colony according to the following guidelines.  
1. Every house with one outgoing pipe but no incoming pipe gets a tank on its roof.
2. Every house with only one incoming and no outgoing pipe gets a tap.
The Geek council has proposed a network of pipes where connections are denoted by three input values: ai, bi, di denoting the pipe of diameter di from house ai to house bi.
Find a more efficient way for the construction of this network of pipes. Minimize the diameter of pipes wherever possible.
Note: The generated output will have the following format. The first line will contain t, denoting the total number of pairs of tanks and taps installed. The next t lines contain three integers each: house number of tank, house number of tap, and the minimum diameter of pipe between them.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dfs(int src,vector<vector<pair<int,int>>>adj,vector<int>&vis,int &dst,int &min)
    {
        vis[src]=1;
        for(auto it:adj[src])
        {
            if(vis[it.first]==0)
            {
                dst=it.first;
                if(it.second<min)
                    min=it.second;
                    
                dfs(it.first,adj,vis,dst,min);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>indeg(n+1,0);
        for(int i=0;i<p;i++)
        {
            int u=a[i];
            int v=b[i];
            int cost=d[i];
            adj[u].push_back({v,cost});
            indeg[v]++;
            // node= adjnode , cost;
        }
        // for(int i=1;i<=n;i++)
        // {
        //     for(auto it:adj[i])
        //     {
        //         cout <<i << " "<<  it.first << "  " << it.second << endl;
        //     }
        // }
        int count=0;
           queue<int>q;
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                count++;
            }
        }
        vector<int>vis(n+1,0);
        vector<vector<int>>result;
        while(q.size()!=0)
        {
            int it=q.front();
            q.pop();
                int min=1e9,dst=-1;
                dfs(it,adj,vis,dst,min);
                if(dst!=-1)
                {
                    vector<int>res;
                    res.push_back(it);
                    res.push_back(dst);
                    res.push_back(min);
                    result.push_back(res);
                }
                
        }
    return result;
    }
};

int main()
{
    int n,p;
    cin >> n >> p;
    vector<int>a(p),b(p),d(p);
    for(int i=0;i<p;i++)
    {
        cin >> a[i] >> b[i] >> d[i];
    }
    Solution s;
    vector<vector<int>>res=s.solve(n,p,a,b,d);
    cout << res.size() << endl;
    for(int i=0;i<res.size();i++)
    {
        cout << res[i][0] <<  " " << res[i][1] <<  " " << res[i][2] << endl;
    }
}