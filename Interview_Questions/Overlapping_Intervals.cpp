/*
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // using O(N*logN)*2 time and O(N)*2 space;
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>>st;
        for(int i=0;i<intervals.size();i++)
        {
            int u=intervals[i][0];
            int v=intervals[i][1];
            if(st.size()==0)
                st.push({u,v});
                
            else
            {
                auto it=st.top();
                int x=it.first;
                int y=it.second;
                if(u>y)
                    st.push({u,v});
                else
                {
                    st.pop();
                    int j=min(x,u);
                    int k=max(y,v);
                    st.push({j,k});
                }
                
            }
        }
        vector<vector<int>>res;
        while(st.size()!=0)
        {
            int u=st.top().first;
            int v=st.top().second;
            res.push_back({u,v});
            st.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
    //optimised Approach
    vector<vector<int>> overlappedIntervaloptimised(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        for(int i=0;i<intervals.size();i++)
        {
            int u=intervals[i][0];
            int v=intervals[i][1];
            if(res.size()==0)
                res.push_back({u,v});
                
            else
            {
                int n=res.size();
                int x=res[n-1][0];
                int y=res[n-1][1];
                if(u>y)
                    res.push_back({u,v});
                else
                {
                   res[n-1][0]=min(u,x);
                   res[n-1][1]=max(v,y);
                }
                
            }
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>>intervals;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        intervals.push_back({x,y});
    }
    Solution s;

    vector<vector<int>>res= s.overlappedIntervaloptimised(intervals);

    for(int i=0;i<res.size();i++)
        cout << res[i][0] <<  " " << res[i][1] << endl;

    return 0;
}