/*
Given a linked list of N nodes. The task is to reverse this list.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
};

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node *curr=head;
        Node *prev=NULL,*temp=NULL;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
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
    head=s.reverseList(head);
    temp=head;
    while(temp!=NULL)
    {
        cout << temp->data <<  " ";
        temp=temp->next;
    }
    return 0;

}