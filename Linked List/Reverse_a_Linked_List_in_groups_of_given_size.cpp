/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    struct node *rev(node *start,node *fin)
    {
        node *curr=start,*prev=NULL;
        while(curr!=fin)
        {
            node *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    struct node *reverse (struct node *head, int k)
    { 
        struct node *temp=head,*prev=NULL,*start=head,*tail=head;
        int count=0;
        struct node *newhead=NULL;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
            if(count==k)
            {
                node *p=rev(start,temp);
                //tail=start;
                if(newhead==NULL)
                {
                    newhead=p;
                }
                else
                {
                    tail->next=p;
                    tail=start;
                }
                start=temp;
                count=0;
            }
            
        }
        node *p=rev(start,temp);
        if(newhead==NULL)
        {
            newhead=p;
        }
        else
        {
            tail->next=p;
        }
        
        return newhead;
    }
};