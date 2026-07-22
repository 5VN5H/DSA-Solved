class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        u = findParent(u);
        v = findParent(v);

        if (u == v) return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        DisjointSet ds(n);

        for (auto &it : connections) {

            int u = it[0];
            int v = it[1];

            ds.unionBySize(u, v);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {

            if (ds.findParent(i) == i)
                components++;
        }

        return components - 1;
    }
};