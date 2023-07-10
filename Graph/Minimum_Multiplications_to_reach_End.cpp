/*
Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end)
    {
        
        vector<int>dist(100000,1e9);
        dist[start]=0;
        queue<int>q;
        q.push(start);
        while(q.size()!=0)
        {
            int x=q.front();
            q.pop();
            for(int i=0;i<arr.size();i++)
            {
                int z=(x*arr[i])%100000;
                if(dist[x]+1<dist[z])
                {
                    dist[z]=dist[x]+1;
                    q.push({z});
                }
            }
        }
        if(dist[end]==1e9)
            return -1;
        else
            return dist[end];
    }
};

int main()
{
    int start,end,n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cin >> start >> end;
    Solution s;
    int res=s.minimumMultiplications(arr,start,end);
    cout << res << endl;
    return 0;


}