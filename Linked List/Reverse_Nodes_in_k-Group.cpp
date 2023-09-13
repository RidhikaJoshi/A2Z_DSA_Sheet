/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *newhead = NULL, *temp1 = NULL;
        ListNode *temp = head, *start = head;
        stack<ListNode *> st;
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->next;
            if (st.size() == k)
            {
                start = temp;
                while (st.size() != 0)
                {
                    ListNode *curr = st.top();
                    curr->next = NULL;
                    if (newhead == NULL)
                    {
                        newhead = st.top();
                        temp1 = st.top();
                    }
                    else
                    {
                        temp1->next = st.top();
                        temp1 = temp1->next;
                    }
                    st.pop();
                }
            }
        }
        if (st.size() != 0 && st.size() < k)
        {
            ListNode *temp2 = start;
            while (temp2 != NULL)
            {
                temp1->next = temp2;
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
        }
        return newhead;
    }
};