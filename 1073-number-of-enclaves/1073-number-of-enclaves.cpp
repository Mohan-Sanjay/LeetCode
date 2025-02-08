class Solution {
public:
    void count(int i,int j,int &n,vector<vector<int>>& grid)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or !grid[i][j])
            return ;
        n--;
        grid[i][j]=0;
        count(i+1,j,n,grid);
        count(i,j+1,n,grid);
        count(i,j-1,n,grid);
        count(i-1,j,n,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n(0);
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]) n++;

        for(int j=0;j<grid[0].size();j++)   // the top
            if(grid[0][j])
                count(0,j,n,grid);

        for(int i=0;i<grid.size();i++)      //the right 
            if(grid[i][0])
                count(i,0,n,grid);

        for(int j=0;j<grid[0].size();j++)   //the down
            if(grid[grid.size()-1][j])
                count(grid.size()-1,j,n,grid);

        for(int i=0;i<grid.size();i++)      //the left
            if(grid[i][grid[0].size()-1])
                count(i,grid[0].size()-1,n,grid);
        return n;
    }
};