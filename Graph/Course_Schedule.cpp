/* There are a total of n tasks you have to pick, labeled from 0 to n-1. Some tasks may have prerequisites tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all tasks, return an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output "No Ordering Possible".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int>res;
       vector<int>indeg(n,0);
       vector<vector<int>>adj(n);
       for(int i=0;i< m;i++)
       {
           int u= prerequisites[i][0];
           int v= prerequisites[i][1];
           adj[v].push_back(u);
           indeg[u]++;
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
           res.push_back(x);
           for(auto it:adj[x])
           {
               indeg[it]--;
               if(indeg[it]==0)
                    q.push(it);
           }
       }
        vector<int>r;
       if(res.size()==n)
        return res;
        else
            return r;
    }
};

int main()
{
    int n,m,x,y;
    cin >> n >> m;
    vector<vector<int>>prerequisites;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        prerequisites.push_back({x,y});
    }
    Solution s;
    vector<int>res=s.findOrder(n,m,prerequisites);
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}