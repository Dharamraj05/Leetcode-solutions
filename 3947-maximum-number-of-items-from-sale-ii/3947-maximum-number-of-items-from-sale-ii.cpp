
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt(n + 1, 0);

        int mn = INT_MAX;

        for (auto &x : items) {
            cnt[x[0]]++;
            mn = min(mn, x[1]);
        }

        vector<int> div(n + 1, 0);

        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j += i)
                div[i] += cnt[j];

        vector<pair<int,int>> v;

        for (auto &x : items) {
            int gain = div[x[0]] - 1;
            if (gain > 0 && x[1] < 2LL * mn)
                v.push_back({x[1], gain});
        }

        sort(v.begin(), v.end());

        long long ans = 0;

        for (auto [price, gain] : v) {
            long long take = min((long long)gain, (long long)budget / price);
            ans += take * 2;
            budget -= take * price;
        }

        ans += budget / mn;

        return ans;
    }
};
