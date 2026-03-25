// Leetcode 3546
// Problem: Equal Sum Grid Partition I
// Topic: Prefix Sum (2D → 1D reduction)
// Diff: medium

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        for(auto &row : grid)
            for(int x : row)
                total += x;


        if(total % 2) return false;

        long long target = total / 2;

        long long curr = 0;
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n; j++) {
                curr += grid[i][j];
            }
            if(curr == target) return true;
        }

        vector<long long> colsum(n, 0);

        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                colsum[j] += grid[i][j];
            }
        }
        curr = 0;
        for(int j = 0; j < n; j++) {
            curr += colsum[j];
            if(curr == target) return true;
        }
        return false;
    }
};
