// Leetocde 3488
// Problem: closest equal element queries
// Topic: array, hash table, binary search
// Diff: medium


class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> pos;
        
        // Store indices of each value
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for (int q : queries) {
            int val = nums[q];
            auto &v = pos[val];
            
            // If only one occurrence
            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // Find index in vector
            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();
            
            int res = INT_MAX;
            
            // Previous index (circular)
            int prev = (idx == 0) ? v.back() : v[idx - 1];
            int d1 = abs(q - prev);
            res = min(res, min(d1, n - d1));
            
            // Next index (circular)
            int next = (idx == v.size() - 1) ? v[0] : v[idx + 1];
            int d2 = abs(q - next);
            res = min(res, min(d2, n - d2));
            
            ans.push_back(res);
        }
        
        return ans;
    }
};
