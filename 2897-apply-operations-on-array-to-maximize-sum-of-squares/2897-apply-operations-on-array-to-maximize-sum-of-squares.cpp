class Solution {
public:
int maxSum(vector<int>& nums, int k) {
const long long MOD = 1e9 + 7;
vector<int> bits(32, 0);

    for (int num : nums) {
        for (int b = 0; b < 32; b++) {
            if (num & (1 << b)) {
                bits[b]++;
            }
        }
    }

    long long ans = 0;

    while (k--) {
        long long num = 0;

        for (int b = 0; b < 32; b++) {
            if (bits[b] > 0) {
                num |= (1 << b);
                bits[b]--;
            }
        }

        ans = (ans + num * num) % MOD;
    }

    return ans;
}
};
