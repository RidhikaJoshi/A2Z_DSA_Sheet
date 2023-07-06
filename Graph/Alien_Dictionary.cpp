/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    string findOrder(string dict[], int N, int K)
    {
        vector<vector<int>>adj(K);
        vector<int>indeg(K,0);
        for(int i=1;i<N;i++)
        {
            string x=dict[i-1];
            string y=dict[i];
            int l=min(x.length(),y.length());
            for(int j=0;j<l;j++)
            {
                if(x[j]!=y[j])
                {
                    adj[x[j]-'a'].push_back(y[j]-'a');
                    indeg[y[j]-'a']++;
                    break;
                }
            }
        }
        string res="";
        queue<int>q;
        for(int i=0;i<K;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        while(q.size()!=0)
        {
            int x=q.front();
            q.pop();
            res+=char(x+'a');
            for(auto it:adj[x])
            {
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        return res;
        
    }
};

int main()
{
    int n,k;
    cin >> n >> k;
    string dict[n];
    for(int i=0;i<n;i++)
    {
        string m;
        cin >> dict[i];
    }
    Solution s;
    string r=s.findOrder(dict,n,k);
    cout << r << endl;
    return 0;

}