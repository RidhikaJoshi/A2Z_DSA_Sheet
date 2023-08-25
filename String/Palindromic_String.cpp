/*
Given a string S, check if it is palindrome or not.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPalindrome(string S)
    {
        int low = 0, high = S.length() - 1;
        while (low <= high)
        {
            if (S[low] != S[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
};