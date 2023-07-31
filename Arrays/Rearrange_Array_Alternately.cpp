/*
Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
        vector<long long>temp;
    	int j=n-1,i=0;
    	while(i<=j)
    	{
    	    temp.push_back(arr[j]);
    	    temp.push_back(arr[i]);
    	    i++;j--;
    	}
    	for(int i=0;i<n;i++)
    	{
    	    arr[i]=temp[i];
    	}
    	
    	 
    }
};