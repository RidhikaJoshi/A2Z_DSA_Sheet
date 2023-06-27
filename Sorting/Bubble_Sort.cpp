
#include<bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[], int n)
{
    while(1)
    {
        int c=-1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]<arr[i-1])
            {
                swap(arr[i],arr[i-1]);
                c=1;
            }
        }
        if(c==-1)
            break;
    }
}
