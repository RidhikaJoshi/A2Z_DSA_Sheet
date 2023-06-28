#include<bits/stdc++.h>
using namespace std;

void swap(vector<int>&arr,int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(vector<int>&arr,int low,int high)
{
    int pivot=arr[low];
    int count=0;
    for(int i=low+1;i<=high;i++)
    {
        if(arr[i]<=pivot)
            count++;
    }
    int pivotindex=low+count;
    swap(arr,low,pivotindex);
    int i=low,j=high;
    while(i<pivotindex && j>pivotindex)
    {
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<pivotindex && j>pivotindex)
             swap(arr,i,j);

    }
    return pivotindex;
}




void QuickSort(vector<int>&arr,int low,int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);
        QuickSort(arr,low,p-1);
        QuickSort(arr,p+1,high);
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
    QuickSort(arr,low,high);
    cout << endl;
    cout << "After Sorting" << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " " ;
    }
    return 0;
}