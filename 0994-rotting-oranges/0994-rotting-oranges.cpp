class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int fresh = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;
        int rottenFresh = 0;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for(int k = 0; k < 4; k++) {

                int nr = row + dx[k];
                int nc = col + dy[k];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] == 1 &&
                   vis[nr][nc] != 2)
                {
                    vis[nr][nc] = 2;
                    rottenFresh++;

                    q.push({{nr, nc}, t + 1});
                }
            }
        }

        //must be equal to the fresh is not -1;
        if(rottenFresh != fresh)
            return -1;

        return time;
    }
};