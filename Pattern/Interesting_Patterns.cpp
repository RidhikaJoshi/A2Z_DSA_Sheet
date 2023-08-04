/*
Given an integer N. Your task is to identify the pattern from the Examples and print the pattern.
N=4
4444444 
4333334 
4322234 
4321234 
4322234 
4333334 
4444444

Input:
N = 3
Output:
33333 
32223 
32123 
32223 
33333

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // using spiral matrix approach
    vector<string> interestingPattern(int N)
    {
        int n=N*2-1;
        vector<vector<int>>res(n,vector<int>(n,0));
        int x=N;
        int left=0,right=n-1,top=0,bottom=n-1;
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                res[top][i]=x;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                res[i][right]=x;
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    res[bottom][i]=x;
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    res[i][left]=x;
                }
                left++;
            }
            x--;
            
        }
        vector<string>s;
        for(int i=0;i<res.size();i++)
        {
            string k="";
            for(int j=0;j<res.size();j++)
            {
                k+=char(res[i][j]+48);
            }
            s.push_back(k);
        }
        return s;
    }
};