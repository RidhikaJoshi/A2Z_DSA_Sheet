/*
Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

Example 1:
Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output: 4
Explanation: 3 is occurring 4 times in 
the given array so it is our answer.

Example 2:
Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output: 5
Explanation: 2 is occurring 5 times in the given array so it is our answer.
*/

#include<bits/stdc++.h>
using namespace std;
// we are using the concept of finding the first and last position of occurence of the target element, then to find the number of occurences cal "c-f+1".
int count(vector<int>& arr, int n, int x)
{
	int low=0,high=n-1;
	int f=-1,c=-1;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]==x)
		{
			f=mid;
			high=mid-1;
		}
		else if(arr[mid]>x)
			high=mid-1;
		else
			low=mid+1;
	}
	low=0,high=n-1;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]==x)
		{
			c=mid;
			low=mid+1;
		}
		else if(arr[mid]>x)
			high=mid-1;
		else
			low=mid+1;
	}
	if(f!=-1 && c!=-1)
		return c-f+1;
	return 0;
}
