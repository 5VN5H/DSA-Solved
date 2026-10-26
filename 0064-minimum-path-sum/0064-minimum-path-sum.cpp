class Solution {
public:
    int solve(int i , int j, vector<vector<int>> &grid,vector<vector<int>>&dp){
        if(i==0&&j==0)return dp[0][0]=grid[0][0];
        if(i<0||j<0)return INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        int up = (solve(i-1,j,grid,dp)==INT_MAX)?INT_MAX:grid[i][j]+solve(i-1,j,grid,dp);
        int right = (solve(i,j-1,grid,dp)==INT_MAX)?INT_MAX:grid[i][j]+solve(i,j-1,grid,dp);
        return dp[i][j]=min(up,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int i = grid.size();
        int j = grid[0].size();
        vector<vector<int>>dp(i,vector(j,-1));
        return solve(i-1,j-1,grid,dp);
    }
};