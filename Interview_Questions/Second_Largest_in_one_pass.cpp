#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
       int arr[n];
       for(int i=0;i<n;i++)
       {
            cin >> arr[i];
       }
       int mx=-1e9,secmx=-1e9;
       for(int i=0;i<n;i++)
       {
            if(arr[i]>mx)
            {   
                secmx=mx;
                mx=arr[i];
            }
            else if(arr[i]<mx && arr[i]>secmx)
            {
                secmx=arr[i];
            }
       }
       cout << mx <<  " " << secmx << endl;

    }
    return 0;
}