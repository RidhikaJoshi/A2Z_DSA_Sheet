/*
Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.
*/

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        queue<pair<int,int>>q;
        int r=hospital.size();
        int c=hospital[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(hospital[i][j]==2)
                    q.push({i,j});
            }
        }
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        int time=0;
        while(q.size()!=0)
        {
            int size=q.size();
            int d=-1;
            for(int j=0;j<size;j++)
            {
                
                int r1=q.front().first;
                int c1=q.front().second;
                q.pop();
              
                for(int k=0;k<4;k++)
                {
                    int nr=r1+delr[k];
                    int nc=c1+delc[k];
                    if(nr>=0 && nr<r && nc>=0 && nc<c)
                    {
                        if(hospital[nr][nc]==1)
                        {
                            hospital[nr][nc]=2;
                            q.push({nr,nc});
                            d=1;
                        }
                    }
                }
            }
        if(d==1)
            time++;
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(hospital[i][j]==1)
                    return -1;
            }
        }
        return time;
    }
};