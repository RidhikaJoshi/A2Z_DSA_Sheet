/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Naive Solution
// Time=o(N) and Space=O(N);
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        set<ListNode *> st;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (st.find(temp) != st.end())
                return temp;
            st.insert(temp);
            temp = temp->next;
        }
        return NULL;
    }
};
// Optimised solution
// using slow and fast pointer
// Time=O(N) and Space=O(1)
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        int c = -1;
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                c = 1;
                break;
            }
        }
        if (c == -1)
            return NULL;
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};