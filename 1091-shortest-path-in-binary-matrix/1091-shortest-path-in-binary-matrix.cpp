class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] || grid[n-1][n-1])
            return -1;

        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});

        grid[0][0] = 1;

        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto curr=q.front();
            q.pop();

            int x=curr.first.first;
            int y=curr.first.second;
            int d=curr.second;

            if(x==n-1 && y==n-1)
                return d;

            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                    grid[nx][ny]=1;
                    q.push({{nx,ny},d+1});
                }
            }
        }

        return -1;
    }
};