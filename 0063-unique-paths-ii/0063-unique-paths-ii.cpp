class Solution {
public:
    int solve(int i,int j, vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid) {
        if(i>=0&&j>=0&&obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==0&&j==0){
            return 1;
        }
        if(i<0||j<0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int left = solve(i,j-1,dp,obstacleGrid);
        int up = solve(i-1,j,dp,obstacleGrid);

        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = obstacleGrid.size();
        int j = obstacleGrid[0].size();
        vector<vector<int>> dp(i, vector<int>(j, -1));
        return solve(i-1, j-1, dp,obstacleGrid);
        // return dp[i-1][j-1]==-1? 0:dp[i-1][j-1];
    }
};