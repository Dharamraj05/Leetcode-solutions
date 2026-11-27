
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), mn = 1501;
        vector<int> freeCnt(n), dp(budget + 1);

        for (int i = 0; i < n; i++) {
            mn = min(mn, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0)
                    freeCnt[i]++;
            }
        }

        for (int i = 0; i < n; i++) {
            int p = items[i][1];

            for (int j = budget; j >= p; j--)
                dp[j] = max(dp[j], dp[j-p] + freeCnt[i] + 1);
        }

        int ans = 0;

        for (int i = 0; i <= budget; i++)
            ans = max(ans, dp[i] + (budget-i)/mn);

        return ans;
    }
};
