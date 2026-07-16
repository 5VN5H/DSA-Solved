class Solution {
public:
    void dfs(vector<int>&vis, vector<int>adj[], int i) {
        vis[i] = 1;

        for (auto it : adj[i]) {
            if (!vis[it]) {
                dfs(vis, adj, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(vis, adj, i);
            }
        }
        return count;
    }
};