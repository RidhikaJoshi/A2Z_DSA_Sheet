/*
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int src,vector<int>adj[],vector<int>&color)
    {
        color[src]=0;
        queue<int>q;
        q.push(src);
        while(q.size()!=0)
        {
            int x=q.front();
            q.pop();
            for(auto it:adj[x])
            {
                if(color[it]==-1)
                {
                    color[it]=!color[x];
                    q.push({it});
                }
                if(color[it]==color[x])
                    return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[])
	{
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
    	        if(bfs(i,adj,color)==false)
    	            return false;
	        }
	    }
	    return true;
	   
	}

};

int main()
{
    int v,e;
    cin >> v >> e;
    vector<int>adj[v];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin >> u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution s;
    if(s.isBipartite(v,adj))
        cout << "1" << endl;
    else    
        cout << "0" << endl;
}