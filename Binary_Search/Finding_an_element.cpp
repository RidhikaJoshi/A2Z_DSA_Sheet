#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&arr, int n, int k)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]>k)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int main()
{
    int n,x;
    cin >> n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        arr.push_back(x);
    }
     int k;
     cin >> k;
    int res=  binarysearch(arr,n,k) ;
    cout << res << endl;
   
    return 0;
}