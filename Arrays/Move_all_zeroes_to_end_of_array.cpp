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

//Intuition: first find the 1st zero int the array and stroe in j
// then iterate through j+1 till the end 
// every time a non-zero number is encountered then we swap elemts at index i and j 
// increase the j pointer by 1

class Solution{
public:
	void pushZerosToEnd(int arr[], int n)
	{
	    int j;
	    for(j=0;j<n;j++)
	    {
	        if(arr[j]==0)
	            break;
	    }
	    for(int i=j+1;i<n;i++)
	    {
	        if(arr[i]!=0)
	        {
	            swap(arr[i],arr[j]);
	            j++;
	        }
	       
	    }

	}
};