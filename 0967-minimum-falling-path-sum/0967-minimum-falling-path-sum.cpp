class Solution {
public:
    int find(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp,vector<vector<bool>>&visit)
    {
        if(i>=n or j>=n or i<0 or j<0)
            return INT_MAX;
        if(i==n-1)
            return matrix[i][j];
        if(visit[i][j])
            return dp[i][j];
        visit[i][j]=true;
        return dp[i][j]=matrix[i][j]+min(find(i+1,j-1,n,matrix,dp,visit),min(find(i+1,j,n,matrix,dp,visit),find(i+1,j+1,n,matrix,dp,visit)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        vector<vector<bool>> visit(n,vector<bool>(n,false));
        int m=INT_MAX;
        for(int i=0;i<n;i++)
            m=min(m,find(0,i,n,matrix,dp,visit));
        return m;
    }
};