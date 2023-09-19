/*There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({end[i], start[i]});
        }
        int count = 1;
        int st = pq.top().second;
        int ed = pq.top().first;
        pq.pop();
        while (pq.size() != 0)
        {
            int x = pq.top().second;
            int y = pq.top().first;
            pq.pop();
            if (x > ed)
            {
                st = x;
                ed = y;
                count++;
            }
        }
        return count;
    }
};