// Leetcode 3761
// Problem: Minimum Absolute Distance Between Mirror Pairs
// Topic: array,  hash table
// Diff: medium



class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastSeen;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            // If current number matches previously stored reverse
            if (lastSeen.count(x)) {
                ans = min(ans, i - lastSeen[x]);
            }

            int rev = reverseNum(x);

            // Store reverse for future matching
            lastSeen[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
