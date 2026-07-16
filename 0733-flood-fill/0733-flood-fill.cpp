class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int inc) {
        int n = image.size();
        int m = image[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        image[sr][sc] = color;

        for (int i = 0; i < 4; i++) {
            int nx = sr + dx[i];
            int ny = sc + dy[i];

            if (nx < n && ny < m && ny >= 0 && nx >= 0 &&
                image[nx][ny] == inc) {
                image[nx][ny] == color;
                dfs(image, nx, ny, color, inc);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int inc = image[sr][sc];

        if (inc == color) {
            return image;
        }
        dfs(image, sr, sc, color, inc);
        return image;
    }
};