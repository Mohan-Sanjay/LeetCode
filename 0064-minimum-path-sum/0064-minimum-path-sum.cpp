class Solution {
public:
    int find(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(find(i+1,j,m,n,grid,dp),find(i,j+1,m,n,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return find(0,0,grid.size(),grid[0].size(),grid,dp);
    }
};