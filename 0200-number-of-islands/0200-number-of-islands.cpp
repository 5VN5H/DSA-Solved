class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int i, int j){
        int n = grid.size();
        int m =grid[0].size();

        vis[i][j]=1;

        int dx[] ={-1,0,1,0};
        int dy[] = {0,-1,0,1};
        for(int k =0; k<4;k++){
            int nx = i+dx[k];
            int ny = j+dy[k];

            //we are checking 1 again here because the adjacent nodes also in first we are checking for the source only;'
            if(nx<n&&ny<m&&nx>=0&&ny>=0&&grid[nx][ny]=='1'&&!vis[nx][ny]){
                dfs(grid,vis,nx,ny);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m =grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){

                if(grid[i][j]=='1'&&!vis[i][j]){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};