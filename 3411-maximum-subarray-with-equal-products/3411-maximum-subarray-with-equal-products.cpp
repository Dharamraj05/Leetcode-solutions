
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int primes[] = {2, 3, 5, 7};

        for (int i = 0; i < n; i++) {
            int sum[4] = {0};
            int mn[4] = {100, 100, 100, 100};
            int mx[4] = {0};

            for (int j = i; j < n; j++) {
                int x = nums[j];

                for (int k = 0; k < 4; k++) {
                    int cnt = 0;
                    while (x % primes[k] == 0) {
                        cnt++;
                        x /= primes[k];
                    }

                    sum[k] += cnt;
                    mn[k] = min(mn[k], cnt);
                    mx[k] = max(mx[k], cnt);
                }

                bool ok = true;
                for (int k = 0; k < 4; k++) {
                    if (sum[k] != mn[k] + mx[k]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
