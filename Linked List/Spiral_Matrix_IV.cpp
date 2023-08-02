/*You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.
*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val=x;
        next=NULL;
    }

};
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
    {
        vector<vector<int>>res(m,vector<int>(n,-1));
        ListNode *curr=head;
        int top=0,bottom=m-1,left=0,right=n-1;
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                if(curr!=NULL)
                {
                    res[top][i]=curr->val;
                    curr=curr->next;
                }
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                if(curr!=NULL)
                {
                    res[i][right]=curr->val;
                    curr=curr->next;
                }
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    if(curr!=NULL)
                    {
                        res[bottom][i]=curr->val;
                        curr=curr->next;
                    }
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    if(curr!=NULL)
                    {
                        res[i][left]=curr->val;
                        curr=curr->next;
                    }
                }
                left++;
            }
        }
        return res;
        
    }
};