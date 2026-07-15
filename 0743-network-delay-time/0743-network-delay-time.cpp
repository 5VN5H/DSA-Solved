class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n+1];

        // Build graph
        for(auto it : times){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n+1,1e9);

        dist[k]=0;

        pq.push({0,k});

        while(!pq.empty()){

            auto node = pq.top();
            pq.pop();

            int dis = node.first;
            int curr = node.second;

            for(auto it : adj[curr]){

                int adjNode = it.first;
                int edgeWeight = it.second;

                if(dis + edgeWeight < dist[adjNode]){

                    dist[adjNode] = dis + edgeWeight;

                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        int ans = 0;

        for(int i=1;i<=n;i++){

            if(dist[i]==1e9)
                return -1;

            ans = max(ans,dist[i]);
        }

        return ans;
    }
};