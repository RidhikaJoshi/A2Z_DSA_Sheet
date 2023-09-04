/*
You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        int n = shifts.size();
        vector<long long> pre(n, 0);
        long long sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int x = shifts[i];
            sum += x;
            pre[i] = sum;
        }
        for (int i = 0; i < n; i++)
        {
            long long x = pre[i];
            x = x % 26;
            char ch;
            if (int(s[i]) + x > 122)
            {
                x = int(s[i]) + x - 123;
                ch = char(int('a') + x);
            }
            else
                ch = char(int(s[i]) + x);
            s[i] = ch;
        }
        return s;
    }
};