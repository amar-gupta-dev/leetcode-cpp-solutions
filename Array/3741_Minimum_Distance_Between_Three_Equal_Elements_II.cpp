// Leetcode 3741
// Problem: Minimum Distance Between Three Equal Elements II
// Topic: array, hash table
// Diff: medium

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);

            // If we have at least 3 occurrences
            if (mp[nums[i]].size() >= 3) {
                int sz = mp[nums[i]].size();
                int i1 = mp[nums[i]][sz - 3];
                int i3 = mp[nums[i]][sz - 1];

                ans = min(ans, 2 * (i3 - i1));
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
