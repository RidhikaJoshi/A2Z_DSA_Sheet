/*Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. The nodes are arranged in a sorted way.*/

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
// Time-O(N)
// Function to remove duplicates from the given linked list

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == temp->data)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}