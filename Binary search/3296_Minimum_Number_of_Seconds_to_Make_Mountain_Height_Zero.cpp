// Leetcode 3296
// Problem: Minimum Number of Seconds to Make Mountain Height Zero
// Topic: Binary Search
// Diff: medium

class Solution {
public:
    long long maxUnits(long long time, long long t) {
        long long left = 0, right = 1e6;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long need = t * (mid * (mid + 1) / 2);
            
            if (need <= time)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return right;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0, right = 1e18;
        long long ans = right;

        while (left <= right) {
            long long mid = (left + right) / 2;
            long long total = 0;

            for (int t : workerTimes) {
                total += maxUnits(mid, t);
                if (total >= mountainHeight) break;
            }

            if (total >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
