/*
Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: If the Graph contains a negative cycle then return an array consisting of only -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S)
    {
        vector<int>dist(V,100000000);
        dist[S]=0;

        
        for(int i=0;i<V-1;i++)
        {
            for(int j=0;j<edges.size();j++)
            {
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
                if(dist[u]+wt<dist[v])
                    dist[v]=dist[u]+wt;
            }
        }


        int c=1;
        for(int i=0;i<edges.size();i++)
        {
            if(dist[edges[i][0]]+edges[i][2]<dist[edges[i][1]])
                {
                   return {-1};
                }
        }
            return dist;
        
    }
};


int main()
{
    int v,e,x,y,z,src;
    cin >> v >> e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++)
    {
        cin >> x >> y >>z ;
        edges.push_back({x,y,z});
    }


    cin >> src;
    Solution s;
    vector<int>res=s.bellman_ford(v,edges,src);
    for(int i=0;i<v;i++)
    {
        cout << res[i] << " ";
    }


    return 0;
}