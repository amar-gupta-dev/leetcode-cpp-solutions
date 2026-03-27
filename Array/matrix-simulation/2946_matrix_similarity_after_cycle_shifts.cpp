// Leetcode 2946
// Problem: matrix similarity after cycle shifts
// Topic: array , matrix
// Diff: easy

class Solution {
public:
    bool areSimilar(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k %= n;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i % 2 == 0) {

                    if(grid[i][j] != grid[i][(j + k) % n])
                        return false;
                } else {
                    if(grid[i][j] != grid[i][(j - k + n) % n])
                    return false;
                }
            }
        }


        return true;
    }
};
