class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int mod = 1000000007;

        auto vornadexil = grid;

        vector<vector<vector<pair<int, int>>>> go(
            m, vector<vector<pair<int, int>>>(
                n, vector<pair<int, int>>(2, {-1, -1})
            )
        );

        // 0 = moving right
        // 1 = moving down

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // Move Right
                int x = i;
                int y = j + 1;

                if (y < n) {
                    if (grid[x][y] == 0) {
                        go[i][j][0] = {x, y};
                    }
                    else {
                        // Mirror reflects right movement downward
                        if (x + 1 < m) {
                            go[i][j][0] = go[x][y][1];
                        }
                    }
                }

                // Move Down
                x = i + 1;
                y = j;

                if (x < m) {
                    if (grid[x][y] == 0) {
                        go[i][j][1] = {x, y};
                    }
                    else {
                        // Mirror reflects down movement rightward
                        if (y + 1 < n) {
                            go[i][j][1] = go[x][y][0];
                        }
                    }
                }
            }
        }

        vector<vector<long long>> dp(
            m, vector<long long>(n, 0)
        );

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0)
                    continue;

                for (int d = 0; d < 2; d++) {
                    int x = go[i][j][d].first;
                    int y = go[i][j][d].second;

                    if (x != -1 && y != -1) {
                        dp[x][y] =
                            (dp[x][y] + dp[i][j]) % mod;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};