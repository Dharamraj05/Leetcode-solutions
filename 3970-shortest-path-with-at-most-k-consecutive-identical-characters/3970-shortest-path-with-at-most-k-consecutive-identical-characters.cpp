class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = LLONG_MAX / 2;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        using State = tuple<long long, int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1, labels[0]});

        while (!pq.empty()) {
            auto [cost, u, cnt, ch] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt]) continue;

            if (u == n - 1) return cost;

            for (auto [v, w] : adj[u]) {
                int nextCnt;

                if (labels[v] == labels[u]) {
                    nextCnt = cnt + 1;
                } else {
                    nextCnt = 1;
                }

                if (nextCnt > k) continue;

                long long newCost = cost + w;

                if (newCost < dist[v][nextCnt]) {
                    dist[v][nextCnt] = newCost;
                    pq.push({newCost, v, nextCnt, labels[v]});
                }
            }
        }

        return -1;
    }
};