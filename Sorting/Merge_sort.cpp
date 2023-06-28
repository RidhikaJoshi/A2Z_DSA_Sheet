#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
// Brute Force Merge Function
void merge(vector<int>&arr,int low,int mid,int high)
{
    vector<int>a;
    vector<int>b;
    for(int i=low;i<=mid;i++)
    {
        a.push_back(arr[i]);
    }
    for(int i=mid+1;i<=high;i++)
    {
        b.push_back(arr[i]);
    }
    int k=low,i=0,j=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            i++;k++;
        }
        else
        {
            arr[k]=b[j];
            j++;k++;
        }
    }
    while(i<a.size())
    {
        arr[k]=a[i];
        i++;k++;
    }
    while(j<b.size())
    {
        arr[k]=b[j];
        j++;k++;
    }
}
/////////////////////////////////////////////
//More Optimised Merge Function
void merge_new(int arr[], int l, int m, int r)
    {
        vector<int>temp;
        int i=l,j=m+1;
        while(i<=m && j<=r)
        {
            if(arr[i]<arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
            
        }
        while(i<=m)
        {
             temp.push_back(arr[i]);
                i++;
        }
        while(j<=r)
        {
            temp.push_back(arr[j]);
            j++;
        }
        j=0;
        for(int i=l;i<=r;i++)
        {
            arr[i]=temp[j];
            j++;
        }
    }

void MergeSort(vector<int>&arr,int low,int high)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
    MergeSort(arr,low,high);
    cout << endl;
    cout << "After sorting" << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " " ;
    }
    return 0;
}