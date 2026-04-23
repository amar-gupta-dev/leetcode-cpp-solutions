// Leetcode 2615
// Problem: Sum of Distances
// Topic: hash map
// Diff: medium


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);

        // Step 1: Group indices by value
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: Process each group
        for (auto& [val, indices] : mp) {
            int m = indices.size();
            vector<long long> prefix(m, 0);

            // Build prefix sum of indices
            prefix[0] = indices[0];
            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + indices[i];
            }

            for (int i = 0; i < m; i++) {
                int idx = indices[i];

                // Left side
                long long leftSum = (i > 0) ? prefix[i - 1] : 0;
                long long leftCount = i;
                long long leftDist = idx * leftCount - leftSum;

                // Right side
                long long rightSum = prefix[m - 1] - prefix[i];
                long long rightCount = m - i - 1;
                long long rightDist = rightSum - idx * rightCount;

                result[idx] = leftDist + rightDist;
            }
        }

        return result;
    }
};
