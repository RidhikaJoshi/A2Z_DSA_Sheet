/*Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. (Not just immidiate Right , but entire List on the Right)
 */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
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
    Node *compute(Node *head)
    {
        head = reverse(head);
        int max = head->data;
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data < max)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
                max = temp->data;
            }
        }
        head = reverse(head);
        return head;
    }
};