class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size();
        int m =mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        int dx[] ={-1,0,1,0};
        int dy[] = {0,-1,0,1};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
            for(int i =0;i<4;i++){
                int row = r+dx[i];
                int col = c+dy[i];

                if(row<n&&row>=0&&col<m&&col>=0&&!vis[row][col]){
                    vis[row][col]=1;
                    dist[row][col]=dist[r][c]+1;
                    q.push({row,col});
                }
            }
            
        }
        return dist;
    }
};