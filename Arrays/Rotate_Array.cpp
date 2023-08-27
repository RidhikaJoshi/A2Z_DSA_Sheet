/*
Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void rotate(int arr[], int low, int high)
    {
        while (low <= high)
        {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
    // Time-O(N)
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(int arr[], int d, int n)
    {
        d = d % n;
        rotate(arr, 0, d - 1);
        rotate(arr, d, n - 1);
        rotate(arr, 0, n - 1);
    }
};