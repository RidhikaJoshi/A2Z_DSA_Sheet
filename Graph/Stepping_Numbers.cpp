/*
Given A and B you have to find all stepping numbers in the range A to B (both inclusive).

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.

For e.g. 123 is a stepping number, but 358 is not a stepping number
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dfs(int s,vector<vector<int>>&adj,int r,int A,int B,unordered_set<int>&st)
    {
        r=r*10+s;
        if(r>=A && r<=B)
        {
            st.insert(r);
        }
        if(r>B)
            return ;
        for(auto it:adj[s])
        {
            dfs(it,adj,r,A,B,st);
        }
    }
    vector<int> stepnum(int A, int B)
    {
        vector<vector<int>>adj(10);
        adj[0].push_back(1);
        for(int i=1;i<=9;i++)
        {
            if((i-1)>=0)
                adj[i].push_back(i-1);
                
            if((i+1)<=9)
                adj[i].push_back(i+1);
        }
        unordered_set<int>st;
        for(int i=1;i<=9;i++)
        {
            int r=0;
        
                dfs(i,adj,r,A,B,st);
        }
    
        
        vector<int>res;
        for(auto it:st)
        {
            res.push_back(it);
        }
        if(A==0)
            res.push_back(0);
        sort(res.begin(),res.end());
        return res;
    }
};

int main()
{
    int A,B;
    cin >> A >> B;
    Solution s;
    vector<int>res=s.stepnum(A,B);
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << " " ;
    }
    return 0;
}