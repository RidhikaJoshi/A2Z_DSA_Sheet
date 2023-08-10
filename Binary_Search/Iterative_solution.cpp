#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int binarySearch(int arr[],int n ,int target)
    {
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>target)
                high=mid-1;
            else    
                low=mid+1;
        }
        return -1;
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
    int res=s.binarySearch(arr,n,target);
    cout << res << endl;
    return 0;

}