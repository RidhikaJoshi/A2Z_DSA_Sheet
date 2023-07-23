/*
Given a singly linked list of N nodes. Find the first node of the loop if the linked list has a loop. If a loop is present return the node data of the first node of the loop else return -1.
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
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        if(head==NULL)
            return -1;
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
        return -1;
        
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow->data;
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
    int res=s.findFirstNode(head);

    
    cout << res << endl;
return 0;
}
    