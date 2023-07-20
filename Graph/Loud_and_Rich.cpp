/*
There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.

You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).

Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
    {
        int n=quiet.size();
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<richer.size();i++)
        {
            int u=richer[i][0];
            int v=richer[i][1];
            adj[u].push_back(v);
            indeg[v]++;
        }


        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=i;
        }

        
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        while(q.size()!=0)
        {
            int x=q.front();
            q.pop();
            for(auto it:adj[x])
            {
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);

                if(quiet[ans[x]]<quiet[ans[it]])
                {
                    ans[it]=ans[x];
                }
            }
        }
        return ans;
        
    }
};