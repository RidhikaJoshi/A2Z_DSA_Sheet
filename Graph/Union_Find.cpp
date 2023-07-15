/*
This problem is to implement disjoint set union. There will be 2 incomplete functions namely union and find. You have to complete these functions. 

Union: Join two subsets into a single set.
isConnected: Determine which subset a particular element is in. This can be used for determining if two elements are in same subset.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    int findUParent(int node,int par[])
    {
        if(node==par[node])
        {
            return node;
        }
        return par[node]=findUParent(par[node],par);
    }
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank1[]) 
    {
        int ulp_u=findUParent(a,par);
        int ulp_v=findUParent(b,par);
        if(ulp_u==ulp_v)
            return;
            
        else if(rank1[ulp_u]<rank1[ulp_v])
        {
            par[ulp_u]=ulp_v;
        }
        else if(rank1[ulp_v]<rank1[ulp_u])
        {
            par[ulp_v]=ulp_u;
        }
        else
        {
            rank1[ulp_u]++;
            par[ulp_v]=ulp_u;
        }
        
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
       return findUParent(x,par)==findUParent(y,par);
    }
};

int main()
{
    int n;
    cin >> n;
    int par[n+1];
    int rank1[n+1];
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
        rank1[i]=0;
    }
    Solution s;
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        char ch;
        int x,y;
        cin >> ch >> x >> y;
   
        if(ch=='U')
            s.union_(x,y,par,rank1);

        else
            cout << s.isConnected(x,y,par,rank1) << endl;
    }
    return 0;
}