// Leetcode 3655
// Problem: XOR after range multiplication Queries II
// Topic: array, divide and conquer
// Diff: hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;
        vector<long long> mult(n, 1);

        // For small k: group by (k, remainder)
        unordered_map<int, unordered_map<int, vector<long long>>> diff;

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= B) {
                // Direct processing for large k
                for (int i = l; i <= r; i += k) {
                    mult[i] = (mult[i] * v) % MOD;
                }
            } else {
                int rem = l % k;
                int start = (l - rem) / k;
                int end = (r - rem) / k;

                if (!diff[k].count(rem))
                    diff[k][rem] = vector<long long>((n + k - 1) / k + 2, 1);

                diff[k][rem][start] =
                    (diff[k][rem][start] * v) % MOD;
                diff[k][rem][end + 1] =
                    (diff[k][rem][end + 1] * modPow(v, MOD - 2)) % MOD;
            }
        }

        // Apply small k updates
        for (auto &[k, remMap] : diff) {
            for (auto &[rem, d] : remMap) {
                long long cur = 1;
                int len = d.size();
                for (int t = 0; t < len; ++t) {
                    cur = (cur * d[t]) % MOD;
                    int idx = rem + t * k;
                    if (idx >= n) break;
                    mult[idx] = (mult[idx] * cur) % MOD;
                }
            }
        }

        // Compute final XOR
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long val = (nums[i] * mult[i]) % MOD;
            ans ^= val;
        }

        return (int)ans;
    }
};
