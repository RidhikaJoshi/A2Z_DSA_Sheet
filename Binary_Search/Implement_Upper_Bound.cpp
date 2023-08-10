/*
The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.

But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. The main difference between the lower and upper bound is in the condition. For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.
*/
#include<bits/stdc++.h>
using namespace std;
// Striver optimal Solution
int upperBound(vector<int> &arr, int x, int n)
{
	int low=0,high=n-1,ans=n;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
                if (arr[mid] > x) {
                  ans = mid;
                  high = mid - 1;
                }
				else
					low=mid+1;
        }	
		return ans;
}
// My Solution
int upperBound(vector<int> &arr, int x, int n)
{
	int low=0,high=n-1,mid;
	while(low<=high)
	{
		 mid=low+(high-low)/2;
		if(arr[mid]>x)
		{
			if(mid==0 && arr[mid]>x)
			{
					return mid;
			}
			else if(mid!=0 && arr[mid-1]<=x)
				return mid;
			else
				high=mid-1;
		}
		else
			low=mid+1;
	}
	return mid+1;
}