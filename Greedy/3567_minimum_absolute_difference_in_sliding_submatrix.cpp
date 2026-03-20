// Leetcode 3567
// Problem: mini absolute diff in sliding submatrix
// Topic: Sliding Window (2D)
// support Topic:Sorting, Matrix, Greedy
// Diff: medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                
                vector<int> vals;
                
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        vals.push_back(grid[x][y]);
                    }
                }
                
                sort(vals.begin(), vals.end());
                
                int minDiff = INT_MAX;
                
                for (int t = 1; t < vals.size(); t++) {
                    if (vals[t] != vals[t - 1]) {
                        minDiff = min(minDiff, vals[t] - vals[t - 1]);
                    }
                }
                
                ans[i][j] = (minDiff == INT_MAX ? 0 : minDiff);
            }
        }
        
        return ans;
    }
};
