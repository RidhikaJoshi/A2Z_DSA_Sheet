/*
Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. Find the value of K.
*/

/* Intuition 

We can easily observe that the number of rotations in an array is equal to the index(0-based index) of its minimum element.
So, in order to solve this problem, we have to find the index of the minimum element.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int findKRotation(int arr[], int n)
	{
	    int low=0,high=n-1;
	    int ans=1e9,ind=-1;
	    while(low<=high)
	    {
	        int mid=low+(high-low)/2;
	        if(arr[low]<=arr[mid])
	        {
	            if(arr[low]<=ans)
	            {
	                ans=arr[low];
	                ind=low;
	            }
	            low=mid+1;
	        }
	        else
	        {
	            if(arr[mid]<=ans)
	            {
	                ans=arr[mid];
	                ind=mid;
	            }
	            high=mid-1;
	        }
	    }
	    return ind;
	}

};