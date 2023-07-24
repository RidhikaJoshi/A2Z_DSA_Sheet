/*
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

NOTE: Don't create a new linked list, instead rearrange the provided one.
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
// Naive approach using Time= O(N)*2 and Space= O(N);
    Node* divide(int N, Node *head)
    {
        vector<int>even;
        vector<int>odd;
        Node *temp=head;
        while(temp!=NULL)
        {
            if(temp->data%2==0)
                even.push_back(temp->data);
            else
                odd.push_back(temp->data);
                
            temp=temp->next;
        }
        temp=head;
        int i=0,j=0;
        while(temp!=NULL)
        {
            if(i<even.size())
            {
                temp->data=even[i];
                i++;
            }
            else
            {
                temp->data=odd[j];
                j++;
            }
            temp=temp->next;
        }
        return head;
    }
// optimised Solution
    class Solution{
public:
    Node* divideOptimised(int N, Node *head)
    {
        Node *evenhead=NULL,*oddhead=NULL,*e=NULL,*o=NULL;
        Node *temp=head;
        while(temp!=NULL)
        {
            //out << temp->data << " ";
            if((temp->data)%2==0)
            {
                if(evenhead==NULL)
                {
                    evenhead=temp;
                    e=temp;
                }
                else
                {
                    e->next=temp;
                    e=e->next;
                }
            }
            if((temp->data)%2!=0)
            {
                if(oddhead==NULL)
                {
                    oddhead=temp;
                    o=temp;
                }
                else
                {
                    o->next=temp;
                    o=o->next;
                }
            }
            temp=temp->next;
        }
        if(evenhead==NULL)
            return oddhead;
        if(oddhead==NULL)
            return evenhead;
        if(o!=NULL && e!=NULL)
        {
            o->next=NULL;
            e->next=oddhead;
        }
        return evenhead;
       
    }
};
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
    head=s.divide(n,head);
    temp=head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }

return 0;
}
