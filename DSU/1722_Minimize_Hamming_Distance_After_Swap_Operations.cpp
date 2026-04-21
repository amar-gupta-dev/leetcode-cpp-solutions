// Leetcode 1722
// Problem: Minimize Hamming Distance After Swap Operations
// Topic: Union-Find (Disjoint Set / DSU)
// Diff: medium



class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        // Step 1: Build groups
        for (auto &e : allowedSwaps) {
            dsu.unite(e[0], e[1]);
        }

        // Step 2: Group indices
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[dsu.find(i)].push_back(i);
        }

        int ans = 0;

        // Step 3: Process each group
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // count source elements
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            // match with target
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};
