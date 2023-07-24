/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(head->next==NULL && n==1)
            return NULL;
        ListNode *slow=head,*fast=head;
        int count=0;
        while(count!=n && fast!=NULL)
        {
            count++;
            fast=fast->next;
        }
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        //cout << slow->val;
        if(slow==head && fast==NULL)
            return head->next;
        slow->next=slow->next->next;
        return head;
        
    }
};

int main()
{
    int n;
    cin >> n;
    ListNode *head=NULL,*temp=NULL;

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        ListNode *curr=new ListNode(x);
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
    }
        int pos;
    cin >> pos;
    ListNode* t=head;
    while(t!=NULL)
    {
        cout << t->val << " " ;
        t=t->next;
    }
    cout << endl;

    Solution s;
    head=s.removeNthFromEnd(head,pos);
    t=head;
    while(t!=NULL)
    {
        cout << t->val << " " ;
        t=t->next;
    }
return 0;
}