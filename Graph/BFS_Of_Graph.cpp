/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.
*/
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int>res;
        vector<int>vis(V,0);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        while(q.size()!=0)
        {
            int x=q.front();
            q.pop();
            res.push_back(x);
            for(auto it:adj[x])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
      return res;
    }
};