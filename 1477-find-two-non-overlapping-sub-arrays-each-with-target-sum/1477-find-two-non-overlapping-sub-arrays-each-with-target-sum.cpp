class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, 1000000);

        int left = 0;
        int sum = 0;
        int ans = 1000000;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (right > 0)
                dp[right] = dp[right - 1];

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && dp[left - 1] != 1000000) {
                    ans = min(ans, len + dp[left - 1]);
                }

                dp[right] = min(dp[right], len);
            }
        }

        if (ans == 1000000)
            return -1;

        return ans;
    }
};