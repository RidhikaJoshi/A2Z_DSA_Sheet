/*
Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list.
*/
#include<bits/stdc++.h>
using namespace std;


void addNode(Node *head, int pos, int data)
{
   Node *curr=new Node(data);
   int count=0;
   Node *temp=head;
   while(count!=pos)
   {
       count++;
       temp=temp->next;
   }
   curr->next=temp->next;
   curr->prev=temp;
   temp->next=curr;
}