// Leetcode 396
// Problem: rotate function
// Topic: array, DP
// Diff: medium

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long sum = accumulate(nums.begin(), nums.end(), 0L);
        long F = 0;

        for(int i = 0; i < n; i++) {
            F += (long)i * nums[i];

        }

        long ans = F;

        for(int k = 1; k < n; k++) {
            F = F + sum - (long) n * nums[n - k];
            ans = max(ans, F);
        }

        return ans;
    }
};
