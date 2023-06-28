
#include<bits/stdc++.h>
using namespace std;


void bubbleSort(vector<int>&arr, int n)
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
     for(int i=0;i<n;i++)
    {
        cout << arr[i] << " " ;
    }
    int low=0,high=n-1;
    bubbleSort(arr,n);
    cout << endl;
    cout << "After sorting" << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " " ;
    }
    return 0;
}