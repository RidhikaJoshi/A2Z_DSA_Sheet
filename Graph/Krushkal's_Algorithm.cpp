/*
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
    // Finding parent function

	int findUParent(int u,int par[])
	{
	    if(u==par[u])
	        return u;
	        
	       return par[u]=findUParent(par[u],par);
	        
	}
    // Union Function


	void Union_size(int u,int v,int par[],int size[])
	{
	    int ulp_u=findUParent(u,par);
	    int ulp_v=findUParent(v,par);
	    if(ulp_u==ulp_v)
	        return;
	        
	   else if(size[ulp_u]<size[ulp_v])
	   {
	       par[ulp_u]=ulp_v;
	       size[ulp_v]+=size[ulp_u];
	   }
	   else
	   {
	       par[ulp_v]=ulp_u;
	       size[ulp_u]+=size[ulp_v];
	   }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
      vector<vector<int>>a;
      for(int i=0;i<V;i++)
      {
          for(auto it:adj[i])
          {
             int u=i;
              int v=it[0];
              int wt=it[1];
              a.push_back({wt,u,v});
          }
      }
      sort(a.begin(),a.end());
      int par[V];
      int size[V];
      for(int i=0;i<V;i++)
      {
          par[i]=i;
          size[i]=1;
      }
      int res=0;
      for(int i=0;i<a.size();i++)
      {
          int wt=a[i][0];
          int u=a[i][1];
          int v=a[i][2];
          if(findUParent(u,par)!=findUParent(v,par))
          {
                Union_size(u,v,par,size);
                res+=wt;
          }
      }
      return res;
      
    }
};

int main()
{
    int V,e;
    cin >> V >> e;
    vector<vector<int>>adj[V];
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin >> u >> v >> wt;
        vector<int>t1;
        t1.push_back(v);
        t1.push_back(wt);
        adj[u].push_back(t1);
        vector<int>t2;
        t2.push_back(u);
        t2.push_back(wt);
        adj[v].push_back(t2);
    }
    Solution s;
    cout <<  s.spanningTree(V,adj) << endl;;

    return 0;

}