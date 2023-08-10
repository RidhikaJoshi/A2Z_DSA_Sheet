/*
Problem Statement: You’re given an unsorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.
*/

#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
	sort(arr,arr+n);
	int low=0,high=n-1;
	int f=-1,c=-1;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
        if (arr[mid] <= x)
        {
            f = arr[mid];
            low = mid + 1;
        }
		else
			high=mid-1;
    }
	low=0,high=n-1;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
        if (arr[mid] >= x) {
                c = arr[mid];
                high = mid - 1;
        }
		else
			low=mid+1;
        }
	return {f,c};

}
