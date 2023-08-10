/*


The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.
*/
#include<bits/stdc++.h>
using namespace std;


int lowerBound(vector<int> arr, int n, int x)
{
	int low=0,high=n-1,mid;
	while(low<=high)
	{
		 mid=low+(high-low)/2;
		if(arr[mid]>=x)
		{
			if(mid==0 && arr[mid]>=x)
				return mid;
			else if(mid!=0 && arr[mid-1]<x)
				return mid;
			else
				high=mid-1;

		}
		else
			low=mid+1;

	}
	return mid+1;
	
}