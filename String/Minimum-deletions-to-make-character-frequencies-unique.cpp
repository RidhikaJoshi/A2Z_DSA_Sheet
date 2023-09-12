/*A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> m1;
        for (int i = 0; i < s.length(); i++)
        {
            m1[s[i]]++;
        }
        unordered_map<int, vector<char>> m;
        for (auto it : m1)
        {
            m[it.second].push_back(it.first);
        }
        int count = 0;
        for (auto it : m)
        {
            if (it.second.size() >= 2)
            {

                for (int i = 0; i < it.second.size() - 1; i++)
                {

                    char ch = it.second[i];
                    // cout  << ch<< endl;
                    int f = it.first;
                    while (m.find(f) != m.end() && f != 0)
                    {
                        f--;
                        count++;
                    }
                    if (f != 0)
                        m[f].push_back(ch);
                }
            }
        }
        return count;
    }
};