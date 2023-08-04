/*
You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.

You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.

Return the maximum total importance of all roads possible after assigning the values optimally.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads)
    {
        map<long long,long long>m;
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            m[u]++;
            m[v]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:m)
        {
            pq.push({it.second,it.first});
        }
        vector<long long>num(n);
        int i=n;
        while(pq.size()!=0)
        {
            int x=pq.top().first;
            int y=pq.top().second;
            pq.pop();
            num[y]=i;
            i--;
        }
        long long count=0;
        for(int i=0;i<roads.size();i++)
        {
            int x=roads[i][0];
            int y=roads[i][1];
            count+=num[x];
            count+=num[y];
        }
        return count;
    }
};