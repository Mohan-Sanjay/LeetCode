class Solution {
public:
    int find(int i,int j,int m,vector<vector<int>>& triangle,vector<vector<int>> &dp)
    {
        if(i==m-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=triangle[i][j]+min(find(i+1,j,m,triangle,dp),find(i+1,j+1,m,triangle,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return find(0,0,m,triangle,dp);
    }
};