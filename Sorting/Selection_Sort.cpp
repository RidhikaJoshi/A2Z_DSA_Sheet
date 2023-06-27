#include<bits/stdc++.h>
using namespace std;

// GFG Question Solution
int select(int arr[], int i)
    {
        int r=arr[i],ind=i;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]>r)
            {
                r=arr[j];
                ind=j;
            }
        }
        swap(arr[i],arr[ind]);
        return r;
    }
     
    void selectionSort(int arr[], int n)
    {
       for(int i=n-1;i>=0;i--)
       {
           int x=select(arr,i);
       }
    }

///////////////////////////////////////////////
// It can be done as the following

void selection_Sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int x=arr[i],ind=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<x)
            {
                x=arr[j];
                ind=j;
            }
        }
        swap(arr[i],arr[ind]);
    }
}