/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void dfs(int src,vector<int>adj[],vector<int>&vis,stack<int>&st)
	{
	    vis[src]=1;
	    for(auto it:adj[src])
	    {
	        if(vis[it]==0)
	            dfs(it,adj,vis,st);
	    }
	    st.push(src);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   stack<int>st;
	   vector<int>vis(V,0);
	   for(int i=0;i<V;i++)
	   {
	       if(vis[i]==0)
	        dfs(i,adj,vis,st);
	   }
	   vector<int>res;
	   while(st.size()!=0)
	   {
	       res.push_back(st.top());
	       st.pop();
	   }
	   return res;
	}
};

int main()
{
    int v,e;
    cin >> e >> v;
    vector<int>adj[v];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Solution s;
    vector<int>res=s.topoSort(v,adj);
    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";
    cout << endl;
return 0;
}