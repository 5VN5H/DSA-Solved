class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int totalL = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    totalL++;
                }
            }
        }

        queue<array<int, 4>> q;
        q.push({sr, sc, energy, 0});

        vector<vector<int>> id(m, vector<int>(n, -1));

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << totalL, false)
                )
            )
        );

        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;
        int allCollected = (1 << totalL) - 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == allCollected)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int index = id[nr][nc];
                        nmask |= (1 << index);
                    }

                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if (!visited[nr][nc][ne][nmask]) {
                        visited[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};