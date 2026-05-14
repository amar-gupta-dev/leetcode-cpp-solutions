// Leetcode 2784
// Problem: check if array is good
// Topic: array
// Diff: easy


class Solution {
public:
    bool isGood(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      int n = nums.size();

      for(int i = 0; i < n - 1; i++){
        if(nums[i] != i + 1)
            return false;
      }  

        return nums[n - 1] == n - 1;
    }
};
