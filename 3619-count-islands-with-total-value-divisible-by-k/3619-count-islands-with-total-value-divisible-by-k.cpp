class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] > 0) {
                    long long sum = 0;

                    queue<pair<int,int>> q;
                    q.push({i, j});
                    sum += grid[i][j];
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int d = 0; d < 4; d++) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];

                            if (nr >= 0 && nr < m &&
                                nc >= 0 && nc < n &&
                                grid[nr][nc] > 0) {

                                sum += grid[nr][nc];
                                q.push({nr, nc});
                                grid[nr][nc] = 0;
                            }
                        }
                    }

                    if (sum % k == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};