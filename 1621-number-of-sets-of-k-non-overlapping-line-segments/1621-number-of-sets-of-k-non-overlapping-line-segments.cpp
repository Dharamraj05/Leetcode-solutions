class Solution {
public:
    long long power(long long a, long long b, long long mod) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1) {
                ans = ans * a % mod;
            }

            a = a * a % mod;
            b /= 2;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;

        int N = n + k - 1;
        int R = 2 * k;

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 1; i <= R; i++) {
            numerator = numerator * (N - R + i) % MOD;
            denominator = denominator * i % MOD;
        }

        long long inverse = power(denominator, MOD - 2, MOD);

        return numerator * inverse % MOD;
    }
};