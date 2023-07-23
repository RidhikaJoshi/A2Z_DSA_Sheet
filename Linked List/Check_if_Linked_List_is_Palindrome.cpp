/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.
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

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
       Node *slow=head,*fast=head;
       while(fast!=NULL && fast->next!=NULL)
       {

           slow=slow->next;
           fast=fast->next->next;
       }
       Node *mid=slow;
       Node *curr=slow,*head2=NULL, * prev=slow;;
       while(curr!=NULL)
       {
           Node *temp=curr->next;
           curr->next=prev;
           prev=curr;
           curr=temp;
       }
       head2=prev;
       while( head!=mid && head2!=mid)
       {
           if(head->data!=head2->data)
            return false;
            
            head=head->next;
            head2=head2->next;
       }
       if(head->data!=head2->data)
            return false;
       return true;
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
    cout << s.isPalindrome(head) << endl;
return 0;
}