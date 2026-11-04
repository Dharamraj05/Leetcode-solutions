class Solution {
public:
    multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;

    void balance() {
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            int val = *it;

            low.erase(it);
            sumLow -= val;

            high.insert(val);
            sumHigh += val;
        }

        while (low.size() < high.size()) {
            auto it = high.begin();
            int val = *it;

            high.erase(it);
            sumHigh -= val;

            low.insert(val);
            sumLow += val;
        }
    }

    void add(int val) {
        if (low.empty() || val <= *prev(low.end())) {
            low.insert(val);
            sumLow += val;
        } else {
            high.insert(val);
            sumHigh += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = low.find(val);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= val;
        } else {
            it = high.find(val);
            high.erase(it);
            sumHigh -= val;
        }

        balance();
    }

    long long getCost() {
        long long median = *prev(low.end());

        long long leftCost =
            median * low.size() - sumLow;

        long long rightCost =
            sumHigh - median * high.size();

        return leftCost + rightCost;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> maritovexi = nums;

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        // DP
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1,
            vector<long long>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int count = 1; count <= k; count++) {
            for (int i = 1; i <= n; i++) {

                dp[count][i] =
                    min(dp[count][i], dp[count][i - 1]);

                if (i >= x && dp[count - 1][i - x] != INF) {
                    dp[count][i] =
                        min(dp[count][i],
                            dp[count - 1][i - x]
                            + cost[i - x]);
                }
            }
        }

        return dp[k][n];
    }
};