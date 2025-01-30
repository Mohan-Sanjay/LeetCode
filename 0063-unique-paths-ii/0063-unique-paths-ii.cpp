class Solution {
public:
    int findpath(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i>=m || j>=n or grid[i][j]==1)
            return 0;
        if(i==m-1 and j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=findpath(i+1,j,m,n,grid,dp)+findpath(i,j+1,m,n,grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return findpath(0,0,obstacleGrid.size(),obstacleGrid[0].size(),obstacleGrid,dp);
    }
};