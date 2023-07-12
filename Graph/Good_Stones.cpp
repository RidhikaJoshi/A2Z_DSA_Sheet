/*
Geek is in a geekland which have a river and some stones in it. Initially geek can step on any stone. Each stone has a number on it representing the value of exact step geek can move. If the number is +ve then geeks can move right and if the number is -ve then geeks can move left. Bad Stones are defined as the stones in which if geeks steps, will reach a never ending loop whereas good stones are the stones which are safe from never ending loops. Return the number of good stones in river.
*/

class Solution{
public:
    bool dfs(int src,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis,vector<int>&res)
    {
        vis[src]=1;
        pathvis[src]=1;
        for(auto it:adj[src])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,pathvis,res)==true)
                    return true;
            }
            else if(pathvis[it]==1)
                return true;
        }
        pathvis[src]=0;
        res.push_back(src);
        return false;
        
    }
    int goodStones(int n,vector<int> &arr)
    {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            if(arr[i]+i <n && arr[i]+i>=0 )
            adj[i].push_back(arr[i]+i);
        }
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            
            if(vis[i]==0)
            {
                dfs(i,adj,vis,pathvis,res);
            }
        }
        return res.size();
       
    }  
};