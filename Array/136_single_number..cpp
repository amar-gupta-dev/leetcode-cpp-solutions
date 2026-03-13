// Leetcode 136
// Problem: single number
// Topic: arrays
// Diff: easy

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};
