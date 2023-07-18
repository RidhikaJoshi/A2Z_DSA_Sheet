/*
Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      if(x==1)
      {
        head_ref=head_ref->next;
        return head_ref;
      }
      int count=1;
      Node *temp=head_ref;
      while(count!=x-1)
      {
          count++;
          temp=temp->next;
      }
      temp->next=temp->next->next;
      return head_ref;
        
        
    }
};