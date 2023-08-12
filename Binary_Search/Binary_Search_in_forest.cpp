/*
There are n trees in a forest. The heights of the trees is stored in array tree[], where tree[i] denotes the height of the ith tree in the forest. If the ith tree is cut at a height H, then the wood collected is tree[i] - H, provided tree[i] > H. If the total woods that needs to be collected is exactly equal to k, find the height H at which every tree should be cut (all trees have to be cut at the same height). If it is not possible then return -1 else return H.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int funct(int tree[],int n, int mid)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(tree[i]>mid)
                count+=tree[i]-mid;
        }
        return count;
    }
    int find_height(int tree[], int n, int k)
    {
        int low=1;
        int high=*max_element(tree,tree+n);
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int cal=funct(tree,n,mid);
            if(cal==k)
               return mid;
            else if(cal>k)
                low=mid+1;
            else
                high=mid-1;
        }
        return ans;
    }
};