class Solution {
public:
long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
int n = nums1.size();
long long k = 1LL * k1 + k2;

    vector<int> diff(n);
    long long total = 0;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        diff[i] = abs(nums1[i] - nums2[i]);
        total += diff[i];
        mx = max(mx, diff[i]);
    }

    if (total <= k)
        return 0;

    int low = 0, high = mx;

    while (low < high) {
        int mid = low + (high - low) / 2;
        long long needed = 0;

        for (int d : diff) {
            if (d > mid)
                needed += d - mid;
        }

        if (needed <= k)
            high = mid;
        else
            low = mid + 1;
    }

    int target = low;
    long long used = 0;
    long long ans = 0;
    long long count = 0;

    for (int d : diff) {
        if (d > target) {
            used += d - target;
            ans += 1LL * target * target;
            count++;
        } else {
            ans += 1LL * d * d;
            if (d == target)
                count++;
        }
    }

    long long remaining = k - used;

    ans -= remaining * (2LL * target - 1);

    return ans;
}


};
