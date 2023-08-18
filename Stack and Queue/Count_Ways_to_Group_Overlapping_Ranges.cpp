/*
You are given a 2D integer array ranges where ranges[i] = [starti, endi] denotes that all integers between starti and endi (both inclusive) are contained in the ith range.

You are to split ranges into two (possibly empty) groups such that:

Each range belongs to exactly one group.
Any two overlapping ranges must belong to the same group.
Two ranges are said to be overlapping if there exists at least one integer that is present in both ranges.

For example, [1, 3] and [2, 5] are overlapping because 2 and 3 occur in both ranges.
Return the total number of ways to split ranges into two groups. Since the answer may be very large, return it modulo 109 + 7.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int countWays(vector<vector<int>>& ranges)
    {
        stack<pair<int,int>>st;
        sort(ranges.begin(),ranges.end());
        for(int i=0;i<ranges.size();i++)
        {
            if(st.size()==0)
                st.push({ranges[i][0],ranges[i][1]});
            else 
            {
                int x=ranges[i][0];
                int y=ranges[i][1];
                while(st.size()!=0 && x>=st.top().first && x<=st.top().second)
                {
                    x=min(x,st.top().first);
                    y=max(y,st.top().second);
                    st.pop();
                }
                st.push({x,y});
            }
        }
        int res=st.size();
        int ans=1;
        for(int i=1;i<=res;i++)
        {
            ans=(ans*2)%mod;
        }
        return ans%mod;
        
    }
};