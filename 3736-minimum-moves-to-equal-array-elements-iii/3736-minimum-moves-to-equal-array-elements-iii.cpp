class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];

        // maximum element finding part
        for(int i = 0; i < n; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
            }
        }

        int ans = 0;

        // here we calculate total moves
        for(int i = 0; i < n; i++) {
            ans += maxi - nums[i];
        }

        return ans;
    }
};