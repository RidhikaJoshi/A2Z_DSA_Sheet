/*
Given a singly linked list and an integer x.Delete xth node from the singly linked list.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *deleteNode(Node *head, int x)
{
    if (x == 1)
        return head->next;
    int count = 1;
    Node *prev = NULL, *temp = head;
    while (count != x)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    return head;
}