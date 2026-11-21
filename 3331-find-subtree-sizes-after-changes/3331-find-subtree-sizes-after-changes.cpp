class Solution {
public:
    vector<vector<int>> tree;
    vector<int> ans;
    vector<int> last[26];
    string s;

    void dfs(int u, int par) {
        ans[u] = 1;

        int ch = s[u] - 'a';
        last[ch].push_back(u);

        for (int v : tree[u]) {
            dfs(v, u);
        }

        int target;

        if (last[ch].size() > 1)
            target = last[ch][last[ch].size() - 2];
        else
            target = par;

        if (target != -1)
            ans[target] += ans[u];

        last[ch].pop_back();
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        this->s = s;

        tree.assign(n, {});
        ans.assign(n, 0);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        dfs(0, -1);
        return ans;
    }
};