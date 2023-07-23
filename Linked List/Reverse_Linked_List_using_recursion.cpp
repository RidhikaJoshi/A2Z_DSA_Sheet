/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode* next;
    ListNode(int x)
    {
        data=x;
        next=NULL;
    }
};

class Solution {
public:
    ListNode* helper(ListNode* head,ListNode* curr,ListNode* prev)
    {
        if(curr==NULL)
            return prev;

        ListNode *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        return helper(head,curr,prev);
        
    }
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *curr=head,*prev=NULL;
        head=helper(head,curr,prev);
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
    Solution s;
    head=s.reverseList(head);
    temp=head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
    return 0;
}