/*Given a circular integer array arr of size N (i.e ., the next element of arr [N-1] is arr[0] ), return the next greater number for every element in arr.
The next greater element of a number x is the first greater number to its traversing order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.*/

#include <bits/stdc++.h>
using namespace std;

// Naive Solution
// Time=O(N^2) and Space=O(N);

class Solution
{
public:
    vector<int> nextGreaterElement(int N, vector<int> &arr)
    {
        vector<int> res;
        for (int i = 0; i < N; i++)
        {
            int c = -1;
            for (int j = (i + 1) % N; j != i; j = (j + 1) % N)
            {
                if (arr[j] > arr[i])
                {
                    res.push_back(arr[j]);
                    c = 1;
                    break;
                }
            }
            if (c == -1)
                res.push_back(-1);
        }
        return res;
    }
};

// Optimised Solution
// Time=O(2N) and Space=O(3N);
class Solution
{
public:
    vector<int> nextGreaterElement(int N, vector<int> &arr)
    {
        vector<int> res;
        vector<int> modify;
        for (int i = 0; i < N; i++)
            modify.push_back(arr[i]);
        for (int i = 0; i < N; i++)
            modify.push_back(arr[i]);
        stack<int> st;
        for (int i = 2 * N - 1; i >= 0; i--)
        {
            if (st.size() == 0)
                res.push_back(-1);
            else if (st.top() > modify[i])
                res.push_back(st.top());
            else
            {
                while (st.size() != 0 && st.top() <= modify[i])
                    st.pop();
                if (st.size() == 0)
                    res.push_back(-1);
                else
                    res.push_back(st.top());
            }
            st.push(modify[i]);
        }
        reverse(res.begin(), res.end());
        res.resize(res.size() / 2);
        return res;
    }
};
// Time=O(2N) and Space-O(N);
vector<int> nextGreaterElement(int N, vector<int> &arr)
{
    stack<int> st;
    for (int i = N - 1; i >= 0; i--)
        st.push(arr[i]);
    vector<int> res;
    for (int i = N - 1; i >= 0; i--)
    {
        if (st.size() == 0)
            res.push_back(-1);
        else if (st.top() > arr[i])
            res.push_back(st.top());
        else
        {
            while (st.size() != 0 && st.top() <= arr[i])
                st.pop();
            if (st.size() == 0)
                res.push_back(-1);
            else
                res.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}