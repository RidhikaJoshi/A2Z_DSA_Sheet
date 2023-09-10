/*

Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. If K is already present in the BST, don't modify the BST.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            Node *curr = new Node(data);
            return curr;
        }
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);

        return node;
    }
};