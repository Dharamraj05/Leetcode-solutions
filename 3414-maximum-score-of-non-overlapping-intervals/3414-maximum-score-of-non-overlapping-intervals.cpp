class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };

    vector<vector<Node>> dp;

    Node solve(vector<vector<int>>& v, int i, int k) {
        if (i == v.size() || k == 0)
            return {0, {}};

        if (dp[i][k].score != -1)
            return dp[i][k];

        Node skip = solve(v, i + 1, k);

        int end = v[i][1];

        int j = upper_bound(
            v.begin() + i + 1,
            v.end(),
            end,
            [](int x, vector<int>& a) {
                return x < a[0];
            }
        ) - v.begin();

        Node take = solve(v, j, k - 1);

        take.score += v[i][2];
        take.ids.push_back(v[i][3]);

        sort(take.ids.begin(), take.ids.end());

        if (take.score > skip.score ||
            (take.score == skip.score && take.ids < skip.ids)) {
            return dp[i][k] = take;
        }

        return dp[i][k] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        dp.assign(n, vector<Node>(5, {-1, {}}));

        return solve(intervals, 0, 4).ids;
    }
};