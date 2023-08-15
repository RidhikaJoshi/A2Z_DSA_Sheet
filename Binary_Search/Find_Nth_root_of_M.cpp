/*
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
	// to calculate the power function
	// overflow case might occur
	// so this function returns 1 if power is equal else 2 if greater else 0 if smaller
	int power(int mid,int n,int m)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*mid;
			if(ans>m)
				return 2;
		}
		if(ans==m)
			return 1;
		else		
			return 0;

	}


	int NthRoot(int n, int m)
	{
	   int low=1,high=m;
	   while(low<=high)
	   {
	       int mid=low+(high-low)/2;
	       if(power(mid,n,m)==1)
	        return mid;
	       else if(power(mid,n,m)==2)
	        high=mid-1;
	       else
	        low=mid+1;
	   }
	   return -1;
	} 
	
	 
};