/*
Given a singly linked list of N nodes.
The task is to find the middle of the linked list. For example, if the linked list is
1-> 2->3->4->5, then the middle node of the list is 3.
If there are two middle nodes(in case, when N is even), print the second middle element.
For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.
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

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
       Node *slow=head,*fast=head;
       while(fast!=NULL && fast->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next->next;
       }
       return slow->data;
    }
};

int main()
{
    int n;
    cin >> n;
    Node *head=NULL,*temp;
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
    }
    Solution s;
    int res= s.getMiddle(head);
    cout << res << endl;;

return 0;
}