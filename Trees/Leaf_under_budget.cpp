/*
Given a binary tree and a budget. Assume you are at the root of the tree(level 1), you need to maximise the count of leaf nodes you can visit in your budget if the cost of visiting a leaf node is equal to the level of that leaf node.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int getCount(Node *root, int k)
    {
        int j = 1;
        vector<int> ans;
        queue<Node *> q;
        q.push(root);
        while (q.size() != 0)
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->left == NULL && curr->right == NULL)
                {
                    // cout << curr->data << endl;
                    ans.push_back(j);
                }
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            j++;
        }
        int sum = 0, count = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            // cout << ans[i] << endl;
            if ((sum + ans[i]) <= k)
            {
                sum += ans[i];
                count++;
            }
            else
                break;
        }
        return count;
    }
};