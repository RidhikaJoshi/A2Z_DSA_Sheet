/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
       vector< vector<int>>graph(numCourses);
       vector<int>indeg(numCourses,0);
       for(int i=0;i<prerequisites.size();i++)
       {
           int x=prerequisites[i][0];
           int y=prerequisites[i][1];
           graph[y].push_back(x);
           indeg[x]++;
       }
       queue<int>q;
       vector<int>res;
       for(int i=0;i<numCourses;i++)
       {
           if(indeg[i]==0)
                q.push(i);
       }
        while(q.size()!=0)
        {
            int x=q.front();
            q.pop();
            res.push_back(x);
            for(auto it:graph[x])
            {
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        if(res.size()==numCourses)
            return res;
            else
            {
                vector<int>r;
                return r;
            }
    }
};