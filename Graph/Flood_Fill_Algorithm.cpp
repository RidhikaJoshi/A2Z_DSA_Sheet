/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.
*/
class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<int>>&vis)
    {
        vis[sr][sc]=1;
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int nr=sr+delr[k];
            int nc=sc+delc[k];
            if(nr>=0 && nr<r && nc>=0 && nc<c)
            {
                if(vis[nr][nc]==0 && image[nr][nc]==image[sr][sc])
                {
                    dfs(r,c,image,nr,nc,newColor,vis);
                    image[nr][nc]=newColor;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int r=image.size();
        int c=image[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        dfs(r,c,image,sr,sc,newColor,vis);
        image[sr][sc]=newColor;
        return image;
    }
};