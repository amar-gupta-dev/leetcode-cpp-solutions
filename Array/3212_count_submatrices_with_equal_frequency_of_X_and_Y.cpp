// Leetcode 3212
// Problem: count submatrices with equal frequency of X and Y
// Topic: array, matrix and prefix sum
// Diff: medium

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        // Prefix sum matrices for X and Y counts
        vector<vector<int>> x(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> y(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Update prefix sums
                x[i + 1][j + 1] = (grid[i][j] == 'X' ? 1 : 0) 
                                  + x[i][j + 1] + x[i + 1][j] - x[i][j];
                y[i + 1][j + 1] = (grid[i][j] == 'Y' ? 1 : 0) 
                                  + y[i][j + 1] + y[i + 1][j] - y[i][j];

                // Check conditions
                if (x[i + 1][j + 1] > 0 && x[i + 1][j + 1] == y[i + 1][j + 1]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
