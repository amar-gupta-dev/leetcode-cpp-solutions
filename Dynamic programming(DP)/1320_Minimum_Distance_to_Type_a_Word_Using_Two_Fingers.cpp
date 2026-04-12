// Leetcode 1320
// Problem: Minimum Distance to Type a Word Using Two Fingers
// Topic: Dynamic programming(DP)
// Diff: hard

class Solution {
public:
    vector<vector<int>> memo;
    
    // Calculate Manhattan distance between two characters
    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0; // No cost for initial placement
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int dfs(const string &word, int index, int otherFinger) {
        if (index == word.size()) return 0;
        
        if (memo[index][otherFinger] != -1)
            return memo[index][otherFinger];
        
        int curr = word[index] - 'A';
        int prev = (index == 0) ? 26 : word[index - 1] - 'A';
        
        // Option 1: Use the same finger that typed the previous character
        int useSame = dist(prev, curr) + dfs(word, index + 1, otherFinger);
        
        // Option 2: Use the other finger
        int useOther = dist(otherFinger, curr) + dfs(word, index + 1, prev);
        
        return memo[index][otherFinger] = min(useSame, useOther);
    }
    
    int minimumDistance(string word) {
        int n = word.size();
        memo.assign(n, vector<int>(27, -1));
        return dfs(word, 0, 26); // 26 represents an unused finger
    }
};
