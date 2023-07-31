/*
Given an array containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
    	  unordered_map<long,long>m;
    	  long p=0,mx=0; 
    	  for(int i=0;i<n;i++)
    	  {
    	      p+=arr[i];
    	      int rem=p%k;
    	        if(rem<0)
    	            rem+=k;
    	      if(rem==0)
    	        mx=i+1;
    	       if(m.find(rem)==m.end())
    	            m[rem]=i;
    	       
    	        if(m.find(rem)!=m.end())
    	            mx=max(mx,i-m[rem]);
    	        
    	  }
    	  return mx;
	}
};