/*
You are given a directed graph with n nodes labeled from 0 to n - 1, where each node has exactly one outgoing edge.

The graph is represented by a given 0-indexed integer array edges of length n, where edges[i] indicates that there is a directed edge from node i to node edges[i].

The edge score of a node i is defined as the sum of the labels of all the nodes that have an edge pointing to i.

Return the node with the highest edge score. If multiple nodes have the same edge score, return the node with the smallest index.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges)
    {
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int x=i;
            int y=edges[i];
            adj[y].push_back(x);
        }
        long long  max=-1;
        int ed=-1;
        for(int i=0;i<n;i++)
        {
            long long count=0;
            for(auto it:adj[i])
            {
                count+=it;
            }
            if(count>max)
            {
                max=count;
                ed=i;
            }
        }
        return ed;
        
    }
};