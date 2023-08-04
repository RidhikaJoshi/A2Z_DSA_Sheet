/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
*/
#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(pq.size()>k)
        {
            pq.pop();
        }
        size=k;
    }
    
    int add(int val)
    {
        pq.push(val);
        if(pq.size()>size)
        {
            cout << pq.top()  << endl;
            pq.pop();
        }

        return pq.top();
        
    }
};