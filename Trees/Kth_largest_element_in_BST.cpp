/*
Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> res;
    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            res.push_back(root->data);
            inorder(root->right);
        }
    }
    int kthLargest(Node *root, int K)
    {
        inorder(root);
        sort(res.rbegin(), res.rend());
        return res[K - 1];
    }
};