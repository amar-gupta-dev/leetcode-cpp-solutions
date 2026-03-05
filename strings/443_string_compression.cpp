//  Leetcode 443
// Problem: string compression
// Topic: string
// Diff: medium

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0; // write pointer
        int i = 0;     // read pointer

        while (i < n) {
            char curr = chars[i];
            int count = 0;

            // count frequency of current char
            while (i < n && chars[i] == curr) {
                i++;
                count++;
            }

            // write char
            chars[index++] = curr;

            // write count if > 1
            if (count > 1) {
                string cnt = to_string(count);
                for (int j = 0; j < cnt.size(); j++) {
                    chars[index++] = cnt[j];
                }
            }
        }
        return index;
    }
};
