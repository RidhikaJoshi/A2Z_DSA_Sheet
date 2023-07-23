/*
Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    int data;
    Node(int x)
    {
        next=NULL;
        data=x;
    }
};

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
       unordered_set<Node*>st;
       Node *temp=head;
       st.insert(temp);
       while(temp!=NULL && temp->next!=NULL)
       {
           if(st.find(temp->next)==st.end())
                st.insert(temp->next);
            else if(st.find(temp->next)!=st.end())
                temp->next=NULL;
           temp=temp->next;     
       }
    }
    bool isloop(Node *head)
    {
        Node *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
               return true;
            }
        }
        return false;

    }
};

int main()
{
    int n;
    cin >> n;
    int pos;
    cin >> pos;
    /// position for loop
    int count=0;
    Node *head=NULL,*temp=NULL,*loop=NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        Node *curr = new Node(x);
        if(count!=pos)
        {
            count++;
            loop=curr;
        }
        if(head==NULL)
        {
            head=curr;
            temp=head;
        }
        else
        {
            temp->next=curr;
            temp=temp->next;
        }

    }
    if(loop!=NULL)
        temp->next=loop;

    Solution s;
    cout << "Before" << endl;
    cout << s.isloop(head) << endl;
    s.removeLoop(head);
    cout << "After" << endl;
    cout << s.isloop(head) << endl;
return 0; 

}