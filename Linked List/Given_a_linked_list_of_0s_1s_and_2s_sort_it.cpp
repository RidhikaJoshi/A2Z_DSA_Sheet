/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.
*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head)
    {
        Node* zerohead=NULL ,*onehead=NULL ,*twohead=NULL,*z,*o,*t;
        Node *temp=head;
        while(temp!=NULL)
        {
            if(temp->data==0)
            {
                if(zerohead==NULL)
                {
                    zerohead=temp;
                    z=temp;
                }
                else
                {
                    z->next=temp;
                    z=z->next;
                }
            }
            else if(temp->data==1)
            {
                if(onehead==NULL)
                {
                    onehead=temp;
                    o=temp;
                }
                else
                {
                    o->next=temp;
                    o=o->next;
                }
            }
            else
            {
                if(twohead==NULL)
                {
                    twohead=temp;
                    t=temp;
                }
                else
                {
                    t->next=temp;
                    t=t->next;
                }
            }
            temp=temp->next;
        }
        if(onehead!=NULL && twohead!=NULL && zerohead!=NULL)
        {
            z->next=onehead;
            o->next=twohead;
            t->next=NULL;
            return zerohead;
        }
        else if(onehead==NULL && twohead!=NULL && zerohead!=NULL)
        {
            z->next=twohead;
            t->next=NULL;
            return zerohead;
        }
        else if(onehead!=NULL && twohead==NULL && zerohead!=NULL)
        {
            z->next=onehead;
            o->next=NULL;
            return zerohead;
        }
        else if(onehead!=NULL && twohead!=NULL && zerohead==NULL)
        {
            o->next=twohead;
            t->next=NULL;
            return onehead;
        }
        else if(onehead!=NULL && twohead==NULL && zerohead==NULL)
        {
            o->next=NULL;
            return onehead;
        }
        else if(onehead==NULL && twohead!=NULL && zerohead==NULL)
        {
            t->next=NULL;
            return twohead;
        }
        else if(onehead==NULL && twohead==NULL && zerohead!=NULL)
        {
            z->next=NULL;
            return zerohead;
        }
        else
        return NULL;
    }
};

int main()
{
    int n;
    cin >> n;
    Node *head=NULL,*temp=NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        Node *curr= new Node(x);
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
    head=s.segregate(head);
    temp=head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }

return 0;
}
