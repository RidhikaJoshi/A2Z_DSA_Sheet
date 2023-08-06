/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int c=0;
        ListNode *temp1=l1,*temp2=l2;
        ListNode* newhead=NULL,*temp=NULL;
        while(temp1!=NULL && temp2!=NULL)
        {
            int x=temp1->val+temp2->val+c;
            int r=x%10;
            c=x/10;
            ListNode *curr=new ListNode(r);
            if(newhead==NULL)
            {
                newhead=curr;
                temp=curr;
            }
            else
            {
                temp->next=curr;
                temp=temp->next;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL)
        {
            int x=temp1->val+c;
            int r=x%10;
            c=x/10;
            ListNode *curr=new ListNode(r);
            if(newhead==NULL)
            {
                newhead=curr;
                temp=curr;
            }
            else
            {
                temp->next=curr;
                temp=temp->next;
            }
            temp1=temp1->next;

        }
        while(temp2!=NULL)
        {
            int x=temp2->val+c;
            int r=x%10;
            c=x/10;
            ListNode *curr=new ListNode(r);
            if(newhead==NULL)
            {
                newhead=curr;
                temp=curr;
            }
            else
            {
                temp->next=curr;
                temp=temp->next;
            }
            temp2=temp2->next;

        }
        if(c!=0)
        {
             ListNode *curr=new ListNode(c);
              temp->next=curr;
        }
    return newhead;
       
    }
};