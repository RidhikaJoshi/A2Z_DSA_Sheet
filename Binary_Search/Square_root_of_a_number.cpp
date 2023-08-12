/*
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
       long long int low=1,high=x,ans=-1;
       while(low<=high)
         {
              long long int mid=low+(high-low)/2;
              long long int sq=mid*mid;
              if(sq==x)
                return mid;
            else if(sq>x)
                high=mid-1;
            else 
            {
                ans=mid;
                low=mid+1;
            }
            
       }
       return ans;
    }
};