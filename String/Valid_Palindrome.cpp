/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string k = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 65 && s[i] <= 90)
            {
                k += tolower(s[i]);
            }
            else if (s[i] >= 97 && s[i] <= 122)
            {
                k += s[i];
            }
            else if (s[i] >= 48 && s[i] <= 57)
                k += s[i];
        }
        int low = 0, high = k.length() - 1;
        while (low <= high)
        {
            if (k[low] != k[high])
                return false;

            low++;
            high--;
        }
        return true;
    }
};