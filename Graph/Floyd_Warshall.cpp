/*
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix)
	{
	    int n=matrix.size();
	    int m=matrix[0].size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	        }
	    }
	    for(int k=0;k<matrix.size();k++)
	    {
	        for(int i=0;i<matrix.size();i++)
	        {
	            for(int j=0;j<matrix[0].size();j++)
	            {
	                if(matrix[i][j]>(matrix[i][k]+matrix[k][j]))
	                    matrix[i][j]=matrix[i][k]+matrix[k][j];
	            }
	        }
	    }
	     for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	    
	}
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>>mat(n);
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        mat[i].push_back(u);
        mat[i].push_back(v);
    }
    Solution s;
    s.shortest_distance(mat);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}