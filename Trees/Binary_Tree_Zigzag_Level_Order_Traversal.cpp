/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        int i = 0;
        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);

        while (q.size() != 0)
        {
            int count = q.size();
            vector<int> r;
            for (int i = 0; i < count; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                r.push_back(curr->val);
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            if (i % 2 != 0)
                reverse(r.begin(), r.end());
            res.push_back(r);
            i++;
        }
        return res;
    }
};