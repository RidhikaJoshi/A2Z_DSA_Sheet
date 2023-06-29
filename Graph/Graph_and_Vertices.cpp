////////////////////////////////////////////
// Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.
class Solution {
  public:
    long long count(int n)
    {
        
        //total edges possible 

        /*

           since every node can be connected to n-1 other nodes so for n nodes total edges possible are n*(n-1) OR n*n(if 

           self node is allowed) but since here undirected graph is being considered so edge from a to b would be same as edge 

           from b to a and hence divided by 2;

           

        */
        long long x=(n)*(n-1)/2;
        //now for every edge we have two options whether to consider it or not 
        return pow(2,x);
    }
};