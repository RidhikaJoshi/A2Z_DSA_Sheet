/*
Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0. C is the position of the node to which the last node is connected. If it is 0 then no loop.
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

int countNodesinLoop(struct Node *head)
{
    if(head==NULL)
        return 0;
        
    Node *slow=head,*fast=head;
    int c=-1;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            c=1;
            break;
        }
    }
    if(c==-1)
        return 0;
        
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    unordered_set<Node*>st;
    while(st.find(slow)==st.end())
    {
        st.insert(slow);
        slow=slow->next;
    }
    int r=st.size();
    return r;
}

int main()
{
    int n;
    cin >> n;
    int pos=0;
    cin >> pos;
    int count=0;
    Node *head=NULL,*temp,*loop=NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        Node *curr=new Node(x);
        if(head==NULL)
        {
            head=curr;
            temp=curr;
        }
        else{
            temp->next=curr;
            temp=temp->next;
        }
        if(count!=pos)
        {
            count++;
            loop=curr;
        }
    }
    if(loop!=NULL)
    {
        temp->next=loop;
    }
    int res= countNodesinLoop(head);
    cout << res << endl;;

return 0;
}