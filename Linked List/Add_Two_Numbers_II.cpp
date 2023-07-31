/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

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
    ListNode *reverse(ListNode* l1)
    {
        ListNode *curr=l1,*prev=NULL;
        while(curr!=NULL)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        l1=reverse(l1);
        l2=reverse(l2);
        int c=0;
        ListNode *temp1=l1,*temp2=l2,*temp=NULL,*head=NULL;
        while(temp1!=NULL && temp2!=NULL)
        {
            int sum=temp1->val+temp2->val+c;
            int r=sum%10;
            c=sum/10;
            ListNode* curr=new ListNode(r);
            if(head==NULL)
            {
                head=curr;
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
            int sum=temp1->val+c;
            int r=sum%10;
            c=sum/10;
            ListNode* curr=new ListNode(r);
            if(head==NULL)
            {
                head=curr;
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
             int sum=temp2->val+c;
            int r=sum%10;
            c=sum/10;
            ListNode* curr=new ListNode(r);
            if(head==NULL)
            {
                head=curr;
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
             ListNode* curr=new ListNode(c);
              temp->next=curr;
        }
        head=reverse(head);
        return head;
        
    }
};