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
       int mn=1e9,secmn=1e9;
       for(int i=0;i<n;i++)
       {
            if(arr[i]<mn)
            {
                secmn=mn;
                mn=arr[i];
            }
            else if(arr[i]>mn && arr[i]<secmn)
            {
                secmn=arr[i];
            }
       }
  
       cout << mn <<  " " << secmn << endl;

    }
    return 0;
}