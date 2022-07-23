void Changecolor(vector<vector<int>>& image,int x,int y,int color,int newcolor)
{
    if(x>=image.size() || x<0 || y>=image[0].size() || y<0 || image[x][y]!=color)
        return;
    image[x][y]=newcolor;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    for(int i=0;i<4;i++)
    {
        Changecolor(image,x+dx[i],y+dy[i],color,newcolor);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    if(newColor==image[x][y])
        return image;
    int givencolor=image[x][y];
    Changecolor(image,x,y,givencolor,newColor);
    return image;
}