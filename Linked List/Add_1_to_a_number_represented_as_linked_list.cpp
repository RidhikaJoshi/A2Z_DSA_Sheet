/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    //
    //
    // Time=O(N)
    Node *reverse(Node *head)
    {
        Node *curr = head, *prev = NULL;
        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    // Time=O(N)
    Node *addOne(Node *head)
    {
        Node *newhead = reverse(head);
        int c = 1;
        Node *temp = newhead;
        Node *head1 = NULL, *t = NULL;
        while (temp != NULL)
        {
            int x = temp->data + c;
            c = x / 10;
            x = x % 10;

            Node *curr = new Node(x);
            if (head1 == NULL)
            {
                head1 = curr;
                t = curr;
            }
            else
            {
                t->next = curr;
                t = t->next;
            }

            temp = temp->next;
        }
        if (c != 0)
        {
            Node *curr = new Node(c);
            t->next = curr;
        }
        head1 = reverse(head1);
        return head1;
    }
};