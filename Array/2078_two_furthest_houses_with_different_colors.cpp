// Leetcode  2078
// Problem: two furthest houses with different colors
// Topic: array, two pointer
// Diff: easy



class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(colors[i] != colors[0]) {
                ans = max(ans, i);
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            if(colors[i] != colors[n - 1]) {
                ans = max(ans, n - 1 - i);
            }
        }

        return ans;
    }
};
