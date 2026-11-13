class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        deque<pair<int, int>> dq;
        long long cost = 0;
        long long ans = 0;

        int right = n - 1;

        for (int left = n - 1; left >= 0; left--) {

            int count = 1;

            while (!dq.empty() && dq.front().first < nums[left]) {
                cost += (long long)(nums[left] - dq.front().first)
                        * dq.front().second;

                count += dq.front().second;
                dq.pop_front();
            }

            dq.push_front({nums[left], count});

            while (cost > k) {
                int value = dq.back().first;

                cost -= value - nums[right];

                dq.back().second--;

                if (dq.back().second == 0) {
                    dq.pop_back();
                }

                right--;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};