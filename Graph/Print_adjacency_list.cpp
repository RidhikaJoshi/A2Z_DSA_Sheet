////////////////////////////////
/*Given the adjacency list representation of an undirected graph
your task is to complete the function printGraph() that takes the number of vertices (V) and the adjacency list as input parameters.
The function should return a new adjacency list, where each adjacency list contains the vertex itself at first position then all its adjacent nodes, in the same order of the given adjacency list of that vertex.
*/
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[])
    {
        
         vector<vector<int>> ans(V);
        for(int i=0;i<V;i++)
        {
            ans[i].push_back(i);
            for(auto it:adj[i])
                ans[i].push_back(it);
            
        }
        return ans;
    }
};