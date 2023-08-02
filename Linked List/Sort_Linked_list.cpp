/*
Given the head of a linked list, return the list after sorting it in ascending order.
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
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val=x;
        next=NULL;
    }
};
class Solution {
public:
// Brute-force Solution O(n^2) bubble sort technique
// Time limit exceded

    ListNode* sortList(ListNode* head)
    {
        if(head==NULL)
            return NULL;
        while(1)
        {
            int c=-1;
            ListNode *prev=head,*curr=head->next;
            while(curr!=NULL)
            {
                if(prev->val>curr->val)
                {
                    int temp=prev->val;
                    prev->val=curr->val;
                    curr->val=temp;
                    c=1;
                }
                prev=prev->next;
                curr=curr->next;
            }
            if(c==-1)
                break;
        }
        return head;
    }
};