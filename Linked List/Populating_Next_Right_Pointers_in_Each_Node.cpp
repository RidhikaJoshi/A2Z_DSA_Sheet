/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.




*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* connect(Node* root)
    {
        if(root==NULL)
            return NULL;
        queue<Node*>q;
        q.push(root);
        while(q.size()!=0)
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                Node *curr=q.front();
                q.pop();
                if((i+1)<count)
                {
                     Node *x=q.front();
                    curr->next=x;
                }
                else
                    curr->next=NULL;
                
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                
            }

        }
    return root;
        
    }
};