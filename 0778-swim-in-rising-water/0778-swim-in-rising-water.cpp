class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({grid[0][0], {0,0}});
        vis[0][0] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == n-1)
                return time;

            for(int k=0;k<4;k++){

                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){

                    vis[nr][nc] = 1;

                    pq.push({
                        max(time, grid[nr][nc]),
                        {nr,nc}
                    });
                }
            }
        }

        return -1;
    }
};