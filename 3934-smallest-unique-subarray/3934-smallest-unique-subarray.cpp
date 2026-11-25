
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const long long B1 = 100019, B2 = 100043;
        const long long M1 = 1000000007, M2 = 1000000009;

        auto check = [&](int len) {
            map<pair<long long,long long>, int> mp;
            long long h1 = 0, h2 = 0, p1 = 1, p2 = 1;

            for (int i = 0; i < len; i++) {
                h1 = (h1 * B1 + nums[i]) % M1;
                h2 = (h2 * B2 + nums[i]) % M2;
                p1 = p1 * B1 % M1;
                p2 = p2 * B2 % M2;
            }

            mp[{h1,h2}]++;

            for (int i = len; i < n; i++) {
                h1 = (h1 * B1 + nums[i] - p1 * nums[i-len] % M1 + M1) % M1;
                h2 = (h2 * B2 + nums[i] - p2 * nums[i-len] % M2 + M2) % M2;
                mp[{h1,h2}]++;
            }

            for (auto x : mp)
                if (x.second == 1) return true;

            return false;
        };

        int l = 1, r = n, ans = n;

        while (l <= r) {
            int mid = l + (r-l)/2;

            if (check(mid)) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return ans;
    }
};
