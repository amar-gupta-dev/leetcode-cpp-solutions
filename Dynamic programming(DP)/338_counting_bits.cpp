// Leetcode 338
// Problem: counting bits
// Topic: DP
// Diff: easy

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        for(int i = 1; i <= n; i++) {

            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
