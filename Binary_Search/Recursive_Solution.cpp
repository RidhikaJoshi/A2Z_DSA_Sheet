#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int binarySearch(int arr[],int low,int high ,int target)
    {
        if(low>high)
            return -1;
        int mid=low+(high-low)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]>target)
            return binarySearch(arr,low,mid-1,target);
        else
            return binarySearch(arr,mid+1,high,target);
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    Solution s;
    int low=0,high=n-1;
    int res=s.binarySearch(arr,low,high,target);
    cout << res << endl;
    return 0;

}