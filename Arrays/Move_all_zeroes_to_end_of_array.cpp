/*
Given an array arr[] of N positive integers. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements.
*/

#include<bits/stdc++.h>
using namespace std;
// Naive Solution Time-O(N^2)
class Solution{
public:
	void pushZerosToEnd(int arr[], int n)
	{
	   for(int i=0;i<n;i++)
	   {
	       if(arr[i]==0)
	       {
	           int j;
	           for( j=i+1;j<n;j++)
	           {
	               if(arr[j]!=0)
	                    break;
	           }
	           if(j!=n)
	                swap(arr[i],arr[j]);
	           
	       }
	   }
	}
};
//Optimised Solution
