// Leetcode 2463
//  Problem: minimum total distance traveled
// Topic: 1D - DP
// Diff: hard


class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        const long long INF = 1e18;

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for(auto &f : factory) {
            long long pos = f[0];
            int cap = f[1];

            vector<long long> new_dp = dp;

            for(int i = 1; i <= n; ++i) {
                long long cost = 0;
                for(int k = 1; k <= min(cap, i); ++k) {
                    cost += abs(robot[i - k] - pos);
                    new_dp[i] = min(new_dp[i], dp[i - k] + cost);
                }
            }
            dp = new_dp;
        }
        return dp[n];
    }
};
