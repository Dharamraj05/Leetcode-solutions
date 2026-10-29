class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, sz;
    vector<int> seg;
    int curPos;

    int dfs(int v, int p) {
        parent[v] = p;
        sz[v] = 1;
        int maxSub = 0;

        for (int u : adj[v]) {
            if (u == p) continue;

            depth[u] = depth[v] + 1;
            int sub = dfs(u, v);
            sz[v] += sub;

            if (sub > maxSub) {
                maxSub = sub;
                heavy[v] = u;
            }
        }
        return sz[v];
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = curPos++;

        if (heavy[v] != -1)
            decompose(heavy[v], h);

        for (int u : adj[v]) {
            if (u != parent[v] && u != heavy[v])
                decompose(u, u);
        }
    }

    void build(int node, int l, int r, vector<int>& base) {
        if (l == r) {
            seg[node] = base[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, base);
        build(node * 2 + 1, mid + 1, r, base);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void updateSeg(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            updateSeg(node * 2, l, mid, idx, val);
        else
            updateSeg(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int querySeg(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return querySeg(node * 2, l, mid, ql, qr) ^
               querySeg(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int pathQuery(int a, int b, int n) {
        int res = 0;

        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]])
                swap(a, b);

            res ^= querySeg(1, 0, n - 1,
                            pos[head[a]], pos[a]);

            a = parent[head[a]];
        }

        if (depth[a] > depth[b])
            swap(a, b);

        res ^= querySeg(1, 0, n - 1,
                        pos[a], pos[b]);

        return res;
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        sz.assign(n, 0);

        curPos = 0;

        dfs(0, -1);
        decompose(0, 0);

        vector<int> base(n);

        for (int i = 0; i < n; i++) {
            base[pos[i]] = 1 << (s[i] - 'a');
        }

        seg.assign(4 * n, 0);
        build(1, 0, n - 1, base);

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);

            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;

                ss >> u >> c;

                s[u] = c;

                int mask = 1 << (c - 'a');

                updateSeg(
                    1, 0, n - 1,
                    pos[u],
                    mask
                );
            }
            else {
                int u, v;
                ss >> u >> v;

                int mask = pathQuery(u, v, n);

                ans.push_back(
                    mask == 0 ||
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return ans;
    }
};