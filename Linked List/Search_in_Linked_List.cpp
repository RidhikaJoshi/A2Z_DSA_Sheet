/*
Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key)
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            if(temp->data==key)
                return true;
                
            temp=temp->next;
        }
        return false;
       
    }
};
