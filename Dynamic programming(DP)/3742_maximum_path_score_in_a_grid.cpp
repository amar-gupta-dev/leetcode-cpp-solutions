// Leetcode 3742
// Problem: maximum path score in a grid
// Topic: DP, array
// Diff: medium



class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;
    const int INF = 1e9;

    int dfs(int i, int j, int k) {
        if (i < 0 || j < 0 || k < 0) return -INF;

        if (i == 0 && j == 0) return 0;

        if (dp[i][j][k] != -1) return dp[i][j][k];

        int cost = (grid[i][j] > 0 ? 1 : 0);
        int nk = k - cost;

        int fromUp = dfs(i - 1, j, nk);
        int fromLeft = dfs(i, j - 1, nk);

        int best = max(fromUp, fromLeft);
        if (best < 0) return dp[i][j][k] = -INF;

        return dp[i][j][k] = best + grid[i][j];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int ans = dfs(m - 1, n - 1, k);
        return (ans < 0 ? -1 : ans);
    }
};
