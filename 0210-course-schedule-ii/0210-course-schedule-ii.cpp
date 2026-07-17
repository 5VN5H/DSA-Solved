class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &it : prerequisites) {

            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Push all nodes having indegree 0
        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto neighbour : adj[node]) {

                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        if (ans.size() == numCourses)
            return ans;

        return {};
    }
};
